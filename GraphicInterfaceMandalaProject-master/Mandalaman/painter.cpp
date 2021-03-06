#define PI 3.1415926535

#include "painter.h"
#include <math.h>
#include <QMouseEvent>
#include <QPainter>


/*
typedef struct coordonneesPolaires{
    double r;
    double theta;
}coordonneesPolaires;

coordonneesPolaires pointTopolar(QPoint p, int mid){
    int x, y;
    x=p.x()-mid;
    y=p.y()-mid;
    coordonneesPolaires c;
    c.r = sqrt(x*x + y*y);
    c.theta = tan((double)y/x);
    return c;
}

coordonneesPolaires rotation(coordonneesPolaires c, int nbSlices){
    c.theta+=2*PI/nbSlices;
    if (c.theta>2*PI){
        c.theta-=2*PI;
    }
    return c;
}

QPoint polarToPoint(coordonneesPolaires c, int mid){
    return QPoint((int) c.r*cos(c.theta) + mid, (int) c.r*sin(c.theta) + mid);
}
*/


painter::painter(QWidget *parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    modified = false;
    scribbling = false;
    myPenWidth = 1;
    myPenColor = Qt::blue;
    nbSlices=1;
    rainbow = false;
    mirror = false;
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

bool painter::saveImage(const QString &fileName/*, const char *fileFormat*/)
{
    QImage visibleImage = image;
    resizeImage(&visibleImage, size());

    if (visibleImage.save(fileName/*, fileFormat*/)) {
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
    if(mirror){
        nbSlices = 2*n;
    } else {
        nbSlices = n;
    }
}

void painter::doGrid()
{
    grid;
}

void painter::setRainbow()
{
    rainbow = !rainbow;
}

void painter::setMirror()
{
    mirror = !mirror;
    if (mirror){
        nbSlices*=2;
    }else{
        nbSlices/=2;
    }
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
        if (nbSlices!=1){
            QPoint p = event->pos();
            //coordonneesPolaires c = pointTopolar(p, height()/2);
            for (int i = 0; i < nbSlices; ++ i){
                if (mirror && i%2==1){
                    QTransform transform = QTransform().translate(height()/2, height()/2).rotate(360*i/nbSlices).scale(-1,1).translate(-height()/2, -height()/2);
                    lastPoints[i] = transform.map(p);
                }else{
                    QTransform transform = QTransform().translate(height()/2, height()/2).rotate(360*i/nbSlices).translate(-height()/2, -height()/2);
                    lastPoints[i] = transform.map(p);
                }

                //lastPoints[i] = polarToPoint(c,height()/2);
                //c = rotation(c, nbSlices);
            }
        } else {
            lastPoint = event->pos();
        }
        scribbling = true;

    }
}

void painter::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && scribbling){
        if (nbSlices!=1){
            QPoint p = event->pos();
            //coordonneesPolaires c = pointTopolar(p, height()/2);
            for (int i = 0; i < nbSlices; ++ i){
                if (mirror && i%2==1){
                    QTransform transform = QTransform().translate(height()/2,height()/2).rotate(360*i/nbSlices).scale(-1,1).translate(-height()/2, -height()/2);
                    drawLineTo(transform.map(p),i);
                }else{
                    QTransform transform = QTransform().translate(height()/2,height()/2).rotate(360*i/nbSlices).translate(-height()/2, -height()/2);
                    drawLineTo(transform.map(p),i);
                }
                //drawLineTo(polarToPoint(c,height()/2), i);
                //c = rotation(c, nbSlices);
            }
        } else {
            drawLineTo(event->pos(), 0);
        }
    }
}

void painter::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && scribbling) {
        if (nbSlices!=1){
            QPoint p = event->pos();
            //coordonneesPolaires c = pointTopolar(p, height()/2);
            for (int i = 0; i < nbSlices; ++ i){
                //drawLineTo(polarToPoint(c,height()/2), i);
                //c = rotation(c, nbSlices);
                if (mirror && i%2==1){
                    QTransform transform = QTransform().translate(height()/2,height()/2).rotate(360*i/nbSlices).scale(-1,1).translate(-height()/2, -height()/2);
                    drawLineTo(transform.map(p),i);
                }else{
                    QTransform transform = QTransform().translate(height()/2,height()/2).rotate(360*i/nbSlices).translate(-height()/2, -height()/2);
                    drawLineTo(transform.map(p),i);
                }

            }
            scribbling = false;
        } else {
            drawLineTo(event->pos(),0);
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

void painter::drawLineTo(const QPoint &endPoint, int slice)
{


    if (nbSlices == 1){
        QPainter painter(&image);
        painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                            Qt::RoundJoin));
        painter.drawLine(lastPoint, endPoint);
        modified = true;

        int rad = (myPenWidth / 2) + 2;
        update(QRect(lastPoint, endPoint).normalized()
                                         .adjusted(-rad, -rad, +rad, +rad));
        lastPoint = endPoint;
    }else{
        QPainter painter(&image);
        if (rainbow){
            QColor hsvColor = myPenColor.toHsv();

            if (!mirror){
            painter.setPen(QPen(QColor::fromHsv((hsvColor.hue()+360*slice/nbSlices)%360, hsvColor.saturation(), hsvColor.value()), myPenWidth, Qt::SolidLine, Qt::RoundCap,
                                Qt::RoundJoin));
            }else{
                if(slice%2==1){
                    painter.setPen(QPen(QColor::fromHsv((hsvColor.hue()+360*(slice-1)/nbSlices)%360, hsvColor.saturation(), hsvColor.value()), myPenWidth, Qt::SolidLine, Qt::RoundCap,
                                        Qt::RoundJoin));
                } else {
                    painter.setPen(QPen(QColor::fromHsv((hsvColor.hue()+360*slice/nbSlices)%360, hsvColor.saturation(), hsvColor.value()), myPenWidth, Qt::SolidLine, Qt::RoundCap,
                                        Qt::RoundJoin));
                }
            }
        }
        else {
        painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                                Qt::RoundJoin));
        }
        painter.drawLine(lastPoints[slice], endPoint);
        modified = true;

        int rad = (myPenWidth / 2) + 2;
        update(QRect(lastPoints[slice], endPoint).normalized()
                                         .adjusted(-rad, -rad, +rad, +rad));
        //lastPoints[slice] = endPoint;
        lastPoints[slice] = endPoint;
    }
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
