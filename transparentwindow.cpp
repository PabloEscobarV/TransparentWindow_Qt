#include "transparentwindow.h"
#include <QString>

TransparentWindow::TransparentWindow(QWidget *parent)
    : QWidget(parent),
    maxresol(1000),
    minresol(100),
    menunum(7)
{
    vbox = new QVBoxLayout(this);
    slider = new QSlider(Qt::Horizontal, this);
    menubar = new QMenuBar(this);


    setWindowTitle("OPACITY");
    slider->setRange(0, maxresol);
    slider->setValue(maxresol);
    connect(slider, &QSlider::valueChanged, this, &TransparentWindow::setWndOpacity);

    crtmenus();
    addmenustobar();
    crtopacitymenu();
    menubar->show();

    vbox->addWidget(menubar);
    setLayout(vbox);
    resize(400, 300);
}

TransparentWindow::~TransparentWindow()
{
    delete[] menus;
}

void TransparentWindow::setWndOpacity(int value)
{
    if (value < minresol)
        value = minresol;
    setWindowOpacity(value / maxresol);
}

void TransparentWindow::crtmenus()
{
    QString menuname("Menu.");
    menus = new QMenu *[menunum];

    for (int i = 0; i < menunum; ++i)
    {
        if (!i)
        {
            menus[i] = new QMenu{QString("opacity"), this};
            continue ;
        }
        menus[i] = new QMenu{QString(menuname).append(QString::number(i)), this};
    }
}

void TransparentWindow::addmenustobar()
{
    for (int i = 0; i < menunum; ++i)
        menubar->addMenu(menus[i]);
}

void TransparentWindow::crtopacitymenu()
{
    setopacityact = new QWidgetAction(this);
    opacitymenu = new QMenu("set opacity", menus[0]);

    setopacityact->setDefaultWidget(slider);
    opacitymenu->addAction(setopacityact);
    menus[0]->addMenu(opacitymenu);
    menus[0]->addSeparator();
}

