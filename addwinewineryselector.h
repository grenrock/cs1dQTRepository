#ifndef ADDWINEWINERYSELECTOR_H
#define ADDWINEWINERYSELECTOR_H

#include <QDialog>

namespace Ui {
class AddWineWinerySelector;
}

class AddWineWinerySelector : public QDialog
{
    Q_OBJECT

public:
    explicit AddWineWinerySelector(QWidget *parent = 0);
    ~AddWineWinerySelector();

private:
    Ui::AddWineWinerySelector *ui;


};

#endif // ADDWINEWINERYSELECTOR_H
