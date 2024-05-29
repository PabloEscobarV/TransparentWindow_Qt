#ifndef TRANSPARENTWINDOW_H
#define TRANSPARENTWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QWidgetAction>

class TransparentWindow : public QWidget
{
    Q_OBJECT
    const qreal     maxresol;
    const qreal     minresol;
    const int       menunum;
    QMenuBar        *menubar;
    QMenu           **menus;
    QMenu           *opacitymenu;
    QLabel          *lbl;
    QVBoxLayout     *vbox;
    QSlider         *slider;
    QAction         *opacityaction;
    QWidgetAction   *setopacityact;
    void            crtmenus();
    void            addmenustobar();
    void            crtopacitymenu();
public:
    TransparentWindow(QWidget *parent = nullptr);
    ~TransparentWindow();
public slots:
    void    setWndOpacity(int value);
};
#endif // TRANSPARENTWINDOW_H
