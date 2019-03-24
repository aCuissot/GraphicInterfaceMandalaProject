#define PI 3.1415926535

#include "painter.h"
#include <math.h>
#include <QMouseEvent>
#include <QPainter>

typedef struct coordonneesSpheriques{
    double r;
    double theta;
}coordonneesSpheriques;

coordonneesSpheriques pointToSpheric(QPoint p, int mid){
    int x, y;
    x=p.x()-mid;
    y=p.y()-mid;
    coordonneesSpheriques c;
    c.r = sqrt(x*x + y*y);
    c.theta = tan((double)y/x);
    return c;
}

coordonneesSpheriques rotation(coordonneesSpheriques c, int nbSlices){
    c.theta+=2*PI/nbSlices;
    if (c.theta>2*PI){
        c.theta-=2*PI;
    }
    return c;
}

QPoint sphericToPoint(coordonneesSpheriques c, int mid){
    return QPoint((int) c.r*cos(c.theta) + mid, (int) c.r*sin(c.theta) + mid);
}

painter::painter(QWidget *parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    modified = false;
    scribbling = false;
    myPenWidth = 1;
    myPenColor = Qt::blue;
    nbSlices=1;
}

bool painter::openImage(const QString &fileName)
{
    QImage loadedImage;
    if (!loadedImage.load(fileName))
        return false;

    QSize newSize = loadedImage.size().expandedTo(size());
    resizeImage(&loadedImage, newSize);
    image = loadedImage;
    modified = false;
    update();
    return true;
}

bool painter::saveImage(const QString &fileName, const char *fileFormat)
{
    QImage visibleImage = image;
    resizeImage(&visibleImage, size());

    if (visibleImage.save(fileName, fileFormat)) {
        modified = false;
        return true;
    } else {
        return false;
    }
}

void painter::setPenColor(const QColor &newColor)
{
    myPenColor = newColor;
}

void painter::setPenWidth(int newWidth)
{
    myPenWidth = newWidth;
}

void painter::setSliceNumber(int n)
{
    nbSlices = n;
}

void painter::clearImage()
{
    image.fill(qRgb(255, 255, 255));
    modified = true;
    update();
}

void painter::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
        scribbling = true;
    }
}

void painter::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && scribbling){
        if (nbSlices!=1){
            QPoint p = event->pos();
            coordonneesSpheriques c = pointToSpheric(p, 250);
            for (int i = 0; i < nbSlices; ++ i){
                drawLineTo(sphericToPoint(c,250));
                c = rotation(c, nbSlices);
            }
        } else {
            drawLineTo(event->pos());
        }
    }
}

void painter::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && scribbling) {
        if (nbSlices!=1){
            QPoint p = event->pos();
            coordonneesSpheriques c = pointToSpheric(p, 250);
            for (int i = 0; i < nbSlices; ++ i){
                drawLineTo(sphericToPoint(c,250));
                c = rotation(c, nbSlices);
            }
            scribbling = false;
        } else {
            drawLineTo(event->pos());
            scribbling = false;
        }
    }
}

void painter::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
}

void painter::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height()) {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

void painter::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.drawLine(lastPoint, endPoint);
    modified = true;

    int rad = (myPenWidth / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized()
                                     .adjusted(-rad, -rad, +rad, +rad));
    lastPoint = endPoint;
}

void painter::resizeImage(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}
