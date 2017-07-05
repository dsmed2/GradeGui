#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QList>
#include <QTextEdit>
#include <QCheckBox>
#include <QSpinBox>

class QDialogButtonBox;
class QTabWidget;
class QPushButton;

class HomeTab: public QWidget
{
   Q_OBJECT
public:
   explicit HomeTab(QWidget* parent = 0);
public slots:
   void addHomeButton();
private:
   QLineEdit* homeworkFinal;
   QLineEdit* testFinal;
   QLineEdit* partFinal;
   QLineEdit* projectFinal;
   QLineEdit* finalFinal;
   QLineEdit* finalFinalGrade;
   QLineEdit* letterGradeFinal;
   QSpinBox* homeworkPerc;
   QSpinBox* testPerc;
   QSpinBox* partPerc;
   QSpinBox* projectPerc;
   QSpinBox* finalPerc;
   QTextEdit* commentBox;
};

class TestTab: public QWidget
{
   Q_OBJECT
public:
   explicit TestTab(QWidget* parent = 0);
public slots:
   void addTestButton();
   void saveToFileTest();
   void loadToFileTest();
private:
   QList<QLineEdit*> testWorkLabel;
   QLineEdit* testGrade;
   QLineEdit* numTest;
   QLineEdit* letterTestLabel;
   QTextEdit* comment;
};

class HomeworkTab: public QWidget
{
   Q_OBJECT
public:
   explicit HomeworkTab(QWidget* parent = 0);

public slots:
   void addHomeButton();
   void saveToFileHome();
   void loadToFileHome();
private:
   QList<QLineEdit*> homeworkLabel;
   QLineEdit* homeGrade;
   QLineEdit* numHomework;
   QLineEdit* letterHomeLabel;
};

class ParticTab: public QWidget
{
   Q_OBJECT
public:
   explicit ParticTab(QWidget* parent = 0);

public slots:
   void addPartButton();
   void saveToPartHome();
   void loadToPartHome();
private:
   QList<QLineEdit*> quizEditLabel;
   QList<QCheckBox*> attendance;
   QList<QLineEdit*> inclassEditLabel;
   QLineEdit* partGrade;
   QLineEdit* numAtten;
   QLineEdit* inclassGrade;
   QTabWidget* partTabs;
   QTextEdit* commentPart;
};

class ProjectTab: public QWidget
{
   Q_OBJECT
public:
   explicit ProjectTab(QWidget* parent = 0);
public slots:
   void addProjButton();
private:
   QList<QLabel*> projects;
   QList<QLineEdit*> projectWorkLabel;
   QLineEdit* projGrade;
   QLineEdit* numProj;
   QLineEdit* letterProjLabel;
   QTabWidget* projectTabs;
};

class FinalTab: public QWidget
{
   Q_OBJECT
public:
   explicit FinalTab(QWidget* parent = 0);
public slots:
   void addFinalButton();
private:
   QLineEdit* finalGrade;
   QLineEdit* letterFinalLabel;
   QLineEdit* finalLabel;
   QTextEdit* commentFinal;
};

class Dialog : public QDialog
{
   Q_OBJECT

public:
   explicit Dialog(QWidget *parent = 0);

private:
   QTabWidget* tabWidget;
   QDialogButtonBox* buttonBox;
};

#endif // DIALOG_H
