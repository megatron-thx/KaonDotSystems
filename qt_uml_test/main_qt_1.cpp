/*
  megatron.thx Tbilisi 2026
*/

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <cstdlib>

class ClickableRect : public QGraphicsRectItem {
public:
    ClickableRect(const QRectF &rect) : QGraphicsRectItem(rect) {}

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override {
        // Example: open file in VS Code at line 42
        system("code -g MyClass.h:42");
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QGraphicsScene scene;

    // Rectangle
    ClickableRect *rect = new ClickableRect(QRectF(50, 50, 200, 100));
    scene.addItem(rect);

    // Text inside rectangle
    QGraphicsTextItem *text = new QGraphicsTextItem("Hello UML World");
    text->setPos(80, 90);
    scene.addItem(text);

    // View setup
    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setDragMode(QGraphicsView::ScrollHandDrag); // pan with mouse
    view.setTransformationAnchor(QGraphicsView::AnchorUnderMouse); // zoom under cursor
    view.show();

    return app.exec();
}
