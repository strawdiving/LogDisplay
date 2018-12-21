#include "chartView.h"

chartView::chartView(QChart *chart, QWidget *parent)
    :QChartView(chart,parent)
{
    // 启用“方框选中区域进行放大显示”的功能
    setRubberBand(QChartView::RectangleRubberBand);

}

void chartView::mousePressEvent(QMouseEvent *event)
{
    QChartView::mousePressEvent(event);
}

void chartView::mouseMoveEvent(QMouseEvent *event)
{
    QChartView::mouseMoveEvent(event);
}

void chartView::mouseReleaseEvent(QMouseEvent *event)
{
    QChartView::mouseReleaseEvent(event);
}

/// overwrite wheel event
void chartView::wheelEvent(QWheelEvent* event)
{
    if(event->delta() > 0) {
        chart()->scroll(0,10);
    }
    else {
        chart()->scroll(0,-10);
    }
}

/// overwrite key press event
void chartView::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Plus:
        chart()->zoomIn();
        break;
    case Qt::Key_Minus:
        chart()->zoomOut();
        break;
    case Qt::Key_Left:
        chart()->scroll(-10,0);
        break;
    case Qt::Key_Right:
        chart()->scroll(10,0);
        break;
    case Qt::Key_Up:
        chart()->scroll(0,10);
        break;
    case Qt::Key_Down:
        chart()->scroll(0,-10);
        break;
    default:
        QGraphicsView::keyPressEvent(event);
        break;
    }

}
