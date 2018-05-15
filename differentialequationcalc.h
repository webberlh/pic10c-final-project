#ifndef DIFFERENTIALEQUATIONCALC_H
#define DIFFERENTIALEQUATIONCALC_H

#include <QMainWindow>
#include <sstream>
#include <string>
#include "lib/headers/symbolicc++.h"

namespace Ui {
class DifferentialEquationCalc;
}

class DifferentialEquationCalc : public QMainWindow
{
    Q_OBJECT

public:
    explicit DifferentialEquationCalc(QWidget *parent = 0);
    ~DifferentialEquationCalc();

private:
    Ui::DifferentialEquationCalc *ui;

private slots:
    void set_order(int) const;
    void perform_computation() const;

signals:
    void computation_result(QString) const;
};

#endif // DIFFERENTIALEQUATIONCALC_H
