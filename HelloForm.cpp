#include "HelloForm.h"

HelloForm::HelloForm()
{
    widget.setupUi(this);
    connect(widget.nameEdit, SIGNAL(textChanged(const QString&)), this, SLOT(textChanged(const QString&)));
}

HelloForm::~HelloForm()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("data.db");
    if (!db.open())
    {
        QMessageBox::critical(0, QObject::tr("Database Error"),
                              db.lastError().text());
    }
}

void HelloForm::textChanged(const QString& text)
{ 
    //QSqlQuery query = runQuery("SELECT * FROM user;");
    //while (query.next())
    {
        
    }
    
    
    if (0 < text.trimmed().length()) {
        widget.helloEdit->setText("Hello " + text.trimmed() + "!");
    } else {
        widget.helloEdit->clear();
    }
}
