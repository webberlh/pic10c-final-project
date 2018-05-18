#include <Python.h>
#include "differentialequationcalc.h"
#include "ui_differentialequationcalc.h"

DifferentialEquationCalc::DifferentialEquationCalc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DifferentialEquationCalc)
{
    ui->setupUi(this);
}

DifferentialEquationCalc::~DifferentialEquationCalc()
{
    delete ui;
}

// *****************
// ***** Slots *****
// *****************
void DifferentialEquationCalc::set_order(int n) const {
    switch(n) {
    // Decided against trying to setup switch statements to reduce code in favor of being easily
    // readable
    case 1:
        // Turn off y'' and y', since y never gets turned off don't need to turn it on
        ui->doubleSpinBox->setEnabled(false);
        ui->doubleSpinBox->setValue(0);
        ui->doubleSpinBox_2->setEnabled(false);
        ui->doubleSpinBox_2->setValue(0);
        break;
    case 2:
        // Turn off y''
        ui->doubleSpinBox->setEnabled(false);
        ui->doubleSpinBox->setValue(0);
        ui->doubleSpinBox_2->setEnabled(true);
        break;
    case 3:
        // Don't turn off any
        ui->doubleSpinBox->setEnabled(true);
        ui->doubleSpinBox_2->setEnabled(true);
        break;
    default:
        break;
    }
}

void DifferentialEquationCalc::perform_computation() const {
    double y_coefficient (ui->doubleSpinBox_3->value());
    double dy_coefficient (ui->doubleSpinBox_2->value());
    double ddy_coefficient (ui->doubleSpinBox->value());

    Py_Initialize();
    PyObject* pName = PyUnicode_DecodeFSDefault("./diff_eq_solver.py");
    PyObject* pModule = PyImport_Import(pName);
    PyObject* pFunc = PyObject_GetAttrString(pModule, "main");
    PyObject_CallObject(pFunc, nullptr);

    Py_DECREF (pName);
    Py_DECREF (pModule);
    Py_DECREF (pFunc);
    Py_Finalize();


    // Send signal with results
    //emit computation_result(result);
}
