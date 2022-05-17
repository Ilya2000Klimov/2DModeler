#ifndef SERIALIZEPREVIEW_H
#define SERIALIZEPREVIEW_H

#include <QDialog>

namespace Ui {
class SerializePreview;
}

class SerializePreview : public QDialog
{
    Q_OBJECT

public:
    explicit SerializePreview(QWidget *parent = nullptr);
    ~SerializePreview();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_comboBox_activated(int index);

private:
    Ui::SerializePreview *ui;
};

#endif // SERIALIZEPREVIEW_H
