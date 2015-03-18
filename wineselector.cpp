#include "wineselector.h"
#include "ui_wineselector.h"
#include "changeprice.h"
#include <QMessageBox>

WineSelector::WineSelector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WineSelector)
{
    ui->setupUi(this);
}

WineSelector::~WineSelector()
{
    delete ui;
}

void WineSelector::PopulateComboBox(){
    for(int i = 0; i < current->winesOffered.size(); i++){
        ui->wine_selector_box->addItem(current->winesOffered[i].name);
    }
}

void WineSelector::SetCurrentWinery(winery *w){
    current = w;
    PopulateComboBox();
}

void WineSelector::on_wine_selector_ok_clicked(){
    {
        if(ui->wine_selector_box->currentText() == "Select Wine")
        {
            QMessageBox::warning(this, tr("Error Message"), tr("Please Select a Winery"));
        }
        else
        {
            for(int i = 0; i < current->winesOffered.size(); i ++)
            {
                if(ui->wine_selector_box->currentText() == current->winesOffered[i].name)
                {
                     ChangePrice changer;
                     changer.SetCurrentWine(&current->winesOffered[i]);
                     changer.setModal(true);
                     changer.exec();
                     this->close();
                     break;
                }
            }
        }
    }
}


