#ifndef PAINTER_H
#define PAINTER_H


#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>

class painter : public QWidget
{
    Q_OBJECT

public:
    painter(QWidget *parent = 0);

    bool openImage(const QString &fileName);
    bool saveImage(const QString &fileName/*, const char *fileFormat*/);
    void setPenColor(const QColor &newColor);
    void setPenWidth(int newWidth);

    bool isModified() const { return modified; }
    QColor penColor() const { return myPenColor; }
    int penWidth() const { return myPenWidth; }
    void setSliceNumber(int);
    void doGrid();
    void setRainbow();
    void setMirror();

public slots:
    void clearImage();


protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void drawLineTo(const QPoint &endPoint, int slice);
    void resizeImage(QImage *image, const QSize &newSize);

    bool modified;
    bool scribbling;
    bool rainbow;
    bool mirror;
    int myPenWidth;
    int nbSlices;
    QColor myPenColor;
    QImage image;
    QPoint lastPoint;
    QImage grid;
    QPoint lastPoints[40];
};
#endif // PAINTER_H
