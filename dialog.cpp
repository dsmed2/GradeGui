#include "dialog.h"
#include "Your Mama"
#include <QTableWidget>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QTableWidget>
#include <QFormLayout>

Dialog::Dialog(QWidget *parent)
   : QDialog(parent)
{
   tabWidget = new QTabWidget;
   tabWidget->addTab(new HomeTab, tr("Home"));
   tabWidget->addTab(new HomeworkTab, tr("Homework"));
   tabWidget->addTab(new ParticTab, tr("Participation"));
   tabWidget->addTab(new TestTab, tr("Test"));
   tabWidget->addTab(new ProjectTab, tr("Projects"));
   tabWidget->addTab(new FinalTab, tr("Final"));

   buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

   connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
   connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

   QVBoxLayout* mainLayout = new QVBoxLayout;
   mainLayout->addWidget(tabWidget);
   mainLayout->addWidget(buttonBox);
   setLayout(mainLayout);

   setWindowTitle(tr("Grade Gui"));
}

//This is the homework section of tabs
//
//
//
HomeworkTab::HomeworkTab(QWidget *parent) : QWidget(parent)
{
   QGroupBox* description = new QGroupBox(tr("Instructions"));
   QTextEdit* words = new QTextEdit(tr("Enter in grades into the fields and then press add. The homework average percentage, the number of homeworks, and the letter grade will show up at the bottom!"));
   words->setReadOnly(true);
   words->setFixedHeight(100);


   QGroupBox* homeBox = new QGroupBox(tr("Homework"));

   for (int i = 0; i < 10; i++)
   {
      QLineEdit* homeLabel = new QLineEdit;
      homeLabel->setFixedWidth(35);
      homeworkLabel.push_back(homeLabel);
   }

   QGroupBox* homeBoxResult = new QGroupBox(tr("Grade Result"));

   QGroupBox* loadAndSave = new QGroupBox;

   QLabel* homeAvg = new QLabel(tr("Homework Average:"));
   homeGrade = new QLineEdit;
   homeGrade->setFixedWidth(85);
   homeGrade->setReadOnly(true);

   QLabel* numHome = new QLabel(tr("Number of Homeworks:"));
   numHomework = new QLineEdit;
   numHomework->setFixedWidth(30);
   numHomework->setReadOnly(true);


   QLabel* letterGrade = new QLabel(tr("Letter Grade:"));
   letterHomeLabel = new QLineEdit;
   letterHomeLabel->setFixedWidth(30);
   letterHomeLabel->setReadOnly(true);

   QPushButton* addButt = new QPushButton(tr("&Add"));
   addButt->show();

   QPushButton* loadButt = new QPushButton(tr("&Load"));
   loadButt->show();

   QPushButton* saveButt = new QPushButton(tr("&Save"));
   saveButt->show();

   QFormLayout* homeLayout = new QFormLayout;
   for (int i = 0; i < 10; i++)
   {
      homeLayout->addRow(tr("Homework %1:").arg(i+1), homeworkLabel[i]);
   }
   homeLayout->addRow(addButt);
   homeBox->setLayout(homeLayout);

   connect(addButt, SIGNAL(clicked()), this, SLOT(addHomeButton()));
   connect(loadButt, SIGNAL(clicked()), this, SLOT(loadToFileHome()));
   connect(addButt, SIGNAL(clicked()), this, SLOT(saveToFileHome()));

   QHBoxLayout* descriptionLayout = new QHBoxLayout;
   descriptionLayout->addWidget(words);
   description->setLayout(descriptionLayout);

   QHBoxLayout* resultsLayout = new QHBoxLayout;
   resultsLayout->addWidget(homeAvg);
   resultsLayout->addWidget(homeGrade);
   resultsLayout->addWidget(numHome);
   resultsLayout->addWidget(numHomework);
   resultsLayout->addWidget(letterGrade);
   resultsLayout->addWidget(letterHomeLabel);
   resultsLayout->addStretch();
   homeBoxResult->setLayout(resultsLayout);

   QHBoxLayout* loadSave = new QHBoxLayout;
   loadSave->addWidget(loadButt);
   loadSave->addWidget(saveButt);
   loadAndSave->setLayout(loadSave);

   QVBoxLayout* mainLayout = new QVBoxLayout;
   mainLayout->addWidget(description);
   mainLayout->addWidget(homeBox);
   mainLayout->addWidget(homeBoxResult);
   mainLayout->addWidget(loadAndSave);
   mainLayout->addStretch(1);
   setLayout(mainLayout);
}

void HomeworkTab::addHomeButton()
{
   int tempNum;
   double sum = 0, count = 0;
   QString temp, letter;
   for (int i = 0; i < homeworkLabel.size(); i++)
   {
      temp = homeworkLabel[i]->text();
      if (temp == "")
         sum += 0;
      else
      {
         tempNum = temp.split(" ")[0].toInt();
         if (tempNum < 0)
            sum += 0;
         else
            sum += tempNum;
         count++;
      }
   }

   if (count == 0)
   {
      homeGrade->setText(tr("NA"));
      numHomework->setText(tr("NA"));
      letterHomeLabel->setText(tr("NA"));
   }
   else
   {
      sum = sum / count;

      if (sum > 89)
         letter = "A";
      else if (sum < 90 && sum > 79)
         letter = "B";
      else if (sum < 80 && sum > 69)
         letter = "C";
      else if (sum < 70 && sum > 59)
         letter = "D";
      else
         letter = "F";

      QString charSum = QString::number(sum);
      QString charCount = QString::number(count);

      homeGrade->setText(tr("%1 %").arg(charSum));
      numHomework->setText(charCount);
      letterHomeLabel->setText(letter);
   }
}

void HomeworkTab::saveToFileHome()
{
}

void HomeworkTab::loadToFileHome()
{
}


//This is the test section of tabs
//
//
//
TestTab::TestTab(QWidget *parent) : QWidget(parent)
{
   QGroupBox* testDescription = new QGroupBox(tr("Instructions"));
   QTextEdit* descriptionBox = new QTextEdit(tr("Enter in grades and press add to receive your final scores!"));
   descriptionBox->setReadOnly(true);
   descriptionBox->setFixedHeight(100);

   QGroupBox* commentBox = new QGroupBox(tr("Comments"));
   comment = new QTextEdit;
   comment->setReadOnly(true);

   QGroupBox* testWorkBox = new QGroupBox(tr("Test"));

   for (int i = 0; i < 4; i++)
   {
      QLineEdit* testLabel = new QLineEdit;
      testLabel->setFixedWidth(35);
      testWorkLabel.push_back(testLabel);
   }

   QGroupBox* testResult = new QGroupBox(tr("Grade Result"));

   QLabel* testAvg = new QLabel(tr("Test Average:"));
   testGrade = new QLineEdit;
   testGrade->setFixedWidth(85);
   testGrade->setReadOnly(true);

   QLabel* numOfTest = new QLabel(tr("Number of Tests:"));
   numTest = new QLineEdit;
   numTest->setFixedWidth(30);
   numTest->setReadOnly(true);


   QLabel* letterGrade = new QLabel(tr("Letter Grade:"));
   letterTestLabel = new QLineEdit;
   letterTestLabel->setFixedWidth(30);
   letterTestLabel->setReadOnly(true);

   QPushButton* addButt = new QPushButton(tr("&Add"));
   addButt->show();


   QFormLayout* testLayout = new QFormLayout;
   for (int i = 0; i < 4; i++)
   {
      testLayout->addRow(tr("Test %1:").arg(i+1), testWorkLabel[i]);
   }
   testLayout->addRow(addButt);
   testWorkBox->setLayout(testLayout);

   connect(addButt, SIGNAL(clicked()), this, SLOT(addTestButton()));

   QHBoxLayout* descriptionLayout = new QHBoxLayout;
   descriptionLayout->addWidget(descriptionBox);
   testDescription->setLayout(descriptionLayout);

   QHBoxLayout* commentLayout = new QHBoxLayout;
   commentLayout->addWidget(comment);
   commentBox->setLayout(commentLayout);

   QHBoxLayout* resultsLayout = new QHBoxLayout;
   resultsLayout->addWidget(testAvg);
   resultsLayout->addWidget(testGrade);
   resultsLayout->addWidget(numOfTest);
   resultsLayout->addWidget(numTest);
   resultsLayout->addWidget(letterGrade);
   resultsLayout->addWidget(letterTestLabel);
   resultsLayout->addStretch();
   testResult->setLayout(resultsLayout);

   QVBoxLayout* mainLayout = new QVBoxLayout;
   mainLayout->addWidget(testDescription);
   mainLayout->addWidget(testWorkBox);
   mainLayout->addWidget(testResult);
   mainLayout->addWidget(commentBox);
   mainLayout->addStretch(1);
   setLayout(mainLayout);
}

void TestTab::addTestButton()
{
   int tempNum;
   double sum = 0, count = 0;
   QString temp, letter;
   for (int i = 0; i < testWorkLabel.size(); i++)
   {
      temp = testWorkLabel[i]->text();
      if (temp == "")
         sum += 0;
      else
      {
         tempNum = temp.split(" ")[0].toInt();
         if (tempNum < 0)
            sum += 0;
         else
            sum += tempNum;
         count++;
      }
   }

   if (count == 0)
   {
      testGrade->setText(tr("NA"));
      numTest->setText(tr("NA"));
      letterTestLabel->setText(tr("NA"));
      comment->setText(tr("NA"));
      return;
   }
   else
      sum = sum / count;

   if (sum > 89)
      letter = "A";
   else if (sum < 90 && sum > 79)
      letter = "B";
   else if (sum < 80 && sum > 69)
      letter = "C";
   else if (sum < 70 && sum > 59)
      letter = "D";
   else
      letter = "F";


   if (sum >= 70)
   {
      comment->setText(tr("You did good my son!"));
      comment->append(tr("\nPhew! You made it, no more sleepless nights for now!"));
      comment->append(tr("\nGood luck next semester, hahahahaha!"));
   }
   else if (sum < 70 && sum > 0)
   {
      comment->setText(tr("You done messed up A Aron! Take yo a** down to OshackHennesy's office right now!"));
      comment->append(tr("\nYOU SHALL NOT PASS!"));
      comment->append(tr("\nYou are the weakest link, Goodbye!"));
   }

   QString charSum = QString::number(sum);
   QString charCount = QString::number(count);

   testGrade->setText(tr("%1 %").arg(charSum));
   numTest->setText(charCount);
   letterTestLabel->setText(letter);
}

void TestTab::saveToFileTest()
{
}

void TestTab::loadToFileTest()
{
}


//This is the project section of tabs
//
//
//
ProjectTab::ProjectTab(QWidget *parent) : QWidget(parent)
{
   QGroupBox* proj1 = new QGroupBox;
   QLabel* proj1Label = new QLabel(tr("Project 1 name:"));
   QLabel* proj1LabelD = new QLabel(tr("Project 1 description:"));
   QLineEdit* proj1Name = new QLineEdit;
   QTextEdit* proj1Desc = new QTextEdit;

   QGroupBox* proj2 = new QGroupBox;
   QLabel* proj2Label = new QLabel(tr("Project 2 name:"));
   QLabel* proj2LabelD = new QLabel(tr("Project 2 description:"));
   QLineEdit* proj2Name = new QLineEdit;
   QTextEdit* proj2Desc = new QTextEdit;

   QGroupBox* projDescription = new QGroupBox(tr("Instructions"));
   QTextEdit* boxDescription = new QTextEdit(tr("Enter in grades and press add to receive your final scores if you dare!"));
   boxDescription->setReadOnly(true);
   boxDescription->setFixedHeight(100);

   QGroupBox* projWorkBox = new QGroupBox(tr("Project"));

   for (int i = 0; i < 2; i++)
   {
      QLabel* proj = new QLabel(tr("Project %1:").arg(i+1));
      projects.push_back(proj);
      QLineEdit* projLabel = new QLineEdit;
      projLabel->setFixedWidth(35);
      projectWorkLabel.push_back(projLabel);
   }

   QGroupBox* projResult = new QGroupBox(tr("Grade Result"));

   QLabel* projAvg = new QLabel(tr("Project Average:"));
   projGrade = new QLineEdit;
   projGrade->setFixedWidth(85);
   projGrade->setReadOnly(true);

   QLabel* numOfProj = new QLabel(tr("Number of Projects:"));
   numProj = new QLineEdit;
   numProj->setFixedWidth(30);
   numProj->setReadOnly(true);


   QLabel* letterGrade = new QLabel(tr("Letter Grade:"));
   letterProjLabel = new QLineEdit;
   letterProjLabel->setFixedWidth(30);
   letterProjLabel->setReadOnly(true);

   QPushButton* addButt = new QPushButton(tr("&Add"));
   addButt->show();

   QHBoxLayout* projGradeLay = new QHBoxLayout;
   for (int i = 0; i < 2; i++)
   {
      projGradeLay->addWidget(projects[i]);
      projGradeLay->addWidget(projectWorkLabel[i]);
   }
   projGradeLay->addWidget(addButt);
   projWorkBox->setLayout(projGradeLay);

   connect(addButt, SIGNAL(clicked()), this, SLOT(addProjButton()));

   QHBoxLayout* projLayout = new QHBoxLayout;
   projLayout->addWidget(boxDescription);
   projDescription->setLayout(projLayout);

   QHBoxLayout* projResultsLayout = new QHBoxLayout;
   projResultsLayout->addWidget(projAvg);
   projResultsLayout->addWidget(projGrade);
   projResultsLayout->addWidget(numOfProj);
   projResultsLayout->addWidget(numProj);
   projResultsLayout->addWidget(letterGrade);
   projResultsLayout->addWidget(letterProjLabel);
   projResultsLayout->addStretch();
   projResult->setLayout(projResultsLayout);

   QVBoxLayout* proj1Box = new QVBoxLayout;
   proj1Box->addWidget(proj1Label);
   proj1Box->addWidget(proj1Name);
   proj1Box->addWidget(proj1LabelD);
   proj1Box->addWidget(proj1Desc);
   proj1->setLayout(proj1Box);

   QVBoxLayout* proj2Box = new QVBoxLayout;
   proj2Box->addWidget(proj2Label);
   proj2Box->addWidget(proj2Name);
   proj2Box->addWidget(proj2LabelD);
   proj2Box->addWidget(proj2Desc);
   proj2->setLayout(proj2Box);

   projectTabs = new QTabWidget;
   projectTabs->addTab(proj1, tr("Project 1"));
   projectTabs->addTab(proj2, tr("Project 2"));

   QVBoxLayout* mainProjLayout = new QVBoxLayout;
   mainProjLayout->addWidget(projDescription);
   mainProjLayout->addWidget(projWorkBox);
   mainProjLayout->addWidget(projResult);
   mainProjLayout->addWidget(projectTabs);
   mainProjLayout->addStretch(1);
   setLayout(mainProjLayout);
}

void ProjectTab::addProjButton()
{
   int tempNum;
   double sum = 0, count = 0;
   QString temp, letter;
   for (int i = 0; i < projectWorkLabel.size(); i++)
   {
      temp = projectWorkLabel[i]->text();
      if (temp == "")
         sum += 0;
      else
      {
         tempNum = temp.split(" ")[0].toInt();
         if (tempNum < 0)
            sum += 0;
         else
            sum += tempNum;
         count++;
      }
   }

   if (count == 0)
   {
      projGrade->setText(tr("NA"));
      numProj->setText(tr("NA"));
      letterProjLabel->setText(tr("NA"));
      return;
   }
   else
      sum = sum / count;

   if (sum > 89)
      letter = "A";
   else if (sum < 90 && sum > 79)
      letter = "B";
   else if (sum < 80 && sum > 69)
      letter = "C";
   else if (sum < 70 && sum > 59)
      letter = "D";
   else
      letter = "F";

   QString charSum = QString::number(sum);
   QString charCount = QString::number(count);
   projGrade->setText(tr("%1 %").arg(charSum));
   numProj->setText(charCount);
   letterProjLabel->setText(letter);
}


//This is the participation section of tabs
//
//
//
ParticTab::ParticTab(QWidget *parent) : QWidget(parent)
{
   QList<QLabel*> quizzLabel;
   QList<QLabel*> inclassLabel;

   QGroupBox* partDescr = new QGroupBox(tr("Instructions"));
   QTextEdit* partDescrBox = new QTextEdit(tr("Enter in grades into the approptiate tabs and press add to receive your final scores if you dare!"));
   partDescrBox->setReadOnly(true);
   partDescrBox->setFixedHeight(50);

   QGroupBox* commentPartBox = new QGroupBox(tr("Comments"));
   commentPart = new QTextEdit;
   commentPart->setReadOnly(true);

   QGroupBox* quiz = new QGroupBox;
   for (int i = 0; i < 15; i++)
   {
      QLineEdit* quizzLabel = new QLineEdit;
      quizzLabel->setFixedWidth(35);
      quizEditLabel.push_back(quizzLabel);
   }

   QGroupBox* attend = new QGroupBox;
   for (int i = 0; i < 32; i++)
   {
      QCheckBox* attenCheck = new QCheckBox(tr("Day %1:").arg(i+1));
      attendance.push_back(attenCheck);
   }

   QGroupBox* inclass = new QGroupBox;
   for (int i = 0; i < 10; i++)
   {
      QLineEdit* inclassEdit = new QLineEdit;
      inclassEdit->setFixedWidth(35);
      inclassEditLabel.push_back(inclassEdit);
   }

   partTabs = new QTabWidget;
   partTabs->setFixedHeight(550);
   partTabs->addTab(quiz, tr("Quizzes"));
   partTabs->addTab(attend, tr("Attendance"));
   partTabs->addTab(inclass, tr("In Class"));

   QGroupBox* partResult = new QGroupBox(tr("Grade Result"));

   QLabel* quizAvg = new QLabel(tr("Quiz Average:"));
   partGrade = new QLineEdit;
   partGrade->setFixedWidth(85);
   partGrade->setReadOnly(true);

   QLabel* numOfAtten = new QLabel(tr("Number of classes attended:"));
   numAtten = new QLineEdit;
   numAtten->setFixedWidth(30);
   numAtten->setReadOnly(true);


   QLabel* inclassAvg = new QLabel(tr("In Class average:"));
   inclassGrade = new QLineEdit;
   inclassGrade->setFixedWidth(85);
   inclassGrade->setReadOnly(true);

   QPushButton* addButt = new QPushButton(tr("&Add"));
   addButt->show();

   QPushButton* loadButt = new QPushButton(tr("&Load"));
   loadButt->show();

   QPushButton* saveButt = new QPushButton(tr("&Save"));
   saveButt->show();

   connect(addButt, SIGNAL(clicked()), this, SLOT(addPartButton()));
   connect(loadButt, SIGNAL(clicked()), this, SLOT(loadToPartHome()));
   connect(addButt, SIGNAL(clicked()), this, SLOT(saveToPartHome()));

   QFormLayout* quizLayout = new QFormLayout;
   for (int i = 0; i < 15; i++)
   {
      quizLayout->addRow(tr("Quiz %1:").arg(i+1),quizEditLabel[i]);
   }
   quiz->setLayout(quizLayout);

   QGridLayout* attenLayout = new QGridLayout;
   for (int i = 0; i < 32; i++)
   {
      attenLayout->addWidget(attendance[i], i+1, 0);
   }
   attenLayout->setAlignment(Qt::AlignRight);
   attend->setLayout(attenLayout);
   attend->setLayoutDirection(Qt::RightToLeft);

   QFormLayout* inclassLayout = new QFormLayout;
   for (int i = 0; i < 10; i++)
   {
      inclassLayout->addRow(tr("In class %1:").arg(i+1),inclassEditLabel[i]);
   }
   inclass->setLayout(inclassLayout);

   QHBoxLayout* partResultsLayout = new QHBoxLayout;
   partResultsLayout->addWidget(quizAvg);
   partResultsLayout->addWidget(partGrade);
   partResultsLayout->addWidget(numOfAtten);
   partResultsLayout->addWidget(numAtten);
   partResultsLayout->addWidget(inclassAvg);
   partResultsLayout->addWidget(inclassGrade);
   partResultsLayout->addStretch();
   partResult->setLayout(partResultsLayout);

   QHBoxLayout* partLayout = new QHBoxLayout;
   partLayout->addWidget(partDescrBox);
   partDescr->setLayout(partLayout);

   QHBoxLayout* commentPartLayout = new QHBoxLayout;
   commentPartLayout->addWidget(commentPart);
   commentPartLayout->addWidget(loadButt);
   commentPartLayout->addWidget(saveButt);
   commentPartBox->setLayout(commentPartLayout);

   QVBoxLayout* mainPartLayout = new QVBoxLayout;
   mainPartLayout->addWidget(partDescr);
   mainPartLayout->addWidget(partTabs);
   mainPartLayout->addWidget(addButt);
   mainPartLayout->addWidget(partResult);
   mainPartLayout->addWidget(commentPartBox);
   mainPartLayout->addStretch(1);
   setLayout(mainPartLayout);
}

void ParticTab::addPartButton()
{
   QString temp;
   int count = 0, count1 = 0, count2 = 0, tempNum;
   double sum = 0, sum1 = 0;
   for (int i=0; i < attendance.size(); i++)
   {
      if (attendance[i]->isChecked())
         count++;
   }

   for (int i = 0; i < quizEditLabel.size(); i++)
   {
      temp = quizEditLabel[i]->text();
      if (temp == "")
         sum += 0;
      else
      {
         tempNum = temp.split(" ")[0].toInt();
         if (tempNum < 0)
            sum += 0;
         else
            sum += tempNum;
         count1++;
      }
   }

   if (count1 == 0)
      partGrade->setText(tr("NA"));
   else
      sum = sum / count1;

   tempNum = 0;

   for (int i = 0; i < inclassEditLabel.size(); i++)
   {
      temp = inclassEditLabel[i]->text();
      if (temp == "")
         sum1 += 0;
      else
      {
         tempNum = temp.split(" ")[0].toInt();
         if (tempNum < 0)
            sum1 += 0;
         else
            sum1 += tempNum;
         count2++;
      }
   }

   if (count2 == 0)
      inclassGrade->setText(tr("NA"));
   else
      sum1 = sum1 / count1;

   if (sum >= 70)
      commentPart->setText(tr("You did good my son on those quizzes!"));
   else
      commentPart->setText(tr("Dang man you need to do better on those quizzes..."));

   if (count >= 22)
      commentPart->append(tr("Nice, there isn't a grade for attending cause I am sure they'll give you full credit!"));
   else
      commentPart->append(tr("Get yo butt to class!"));

   if (sum1 >= 70)
      commentPart->append(tr("Well it looks like you are not totally useless in class!"));
   else
      commentPart->append(tr("You still done messed up in class A Aron!"));

   QString charSum = QString::number(sum);
   QString charCount = QString::number(count);
   QString charSum1 = QString::number(sum1);
   partGrade->setText(tr("%1 %").arg(charSum));
   numAtten->setText(charCount);
   inclassGrade->setText(tr("%1 %").arg(charSum1));
}

void ParticTab::saveToPartHome()
{
}

void ParticTab::loadToPartHome()
{
}


//This is the final section of tabs
//
//
//
FinalTab::FinalTab(QWidget *parent) : QWidget(parent)
{
   QLabel* finalName = new QLabel(tr("Final"));
   finalLabel = new QLineEdit;
   QLabel* finalDate = new QLabel(tr("Final Date:"));
   QLineEdit* finalDateLabel = new QLineEdit;
   finalLabel->setFixedWidth(35);
   finalDateLabel->setFixedWidth(100);

   QGroupBox* finalDesc = new QGroupBox(tr("Instructions"));
   QTextEdit* finalInstr = new QTextEdit(tr("Enter in grades and press add to receive your final scores if you dare! And better hope you passed son!"));
   finalInstr->setReadOnly(true);
   finalInstr->setFixedHeight(100);

   QGroupBox* finalResults = new QGroupBox(tr("Grade Results"));
   QLabel* finalAvg = new QLabel(tr("Final Average"));
   finalGrade = new QLineEdit;
   finalGrade->setFixedWidth(85);
   finalGrade->setReadOnly(true);

   QLabel* letterGrade = new QLabel(tr("Letter Grade"));
   letterFinalLabel = new QLineEdit;
   letterFinalLabel->setFixedWidth(30);
   letterFinalLabel->setReadOnly(true);

   QGroupBox* finals = new QGroupBox(tr("Final Grade"));
   QPushButton* finalAdd = new QPushButton(tr("&Add"));
   finalAdd->show();

   connect(finalAdd, SIGNAL(clicked()), this, SLOT(addFinalButton()));

   QGroupBox* commentFinalBox = new QGroupBox(tr("Comments"));
   commentFinal = new QTextEdit;
   commentFinal->setReadOnly(true);

   QHBoxLayout* finalLayout = new QHBoxLayout;
   finalLayout->addWidget(finalInstr);
   finalDesc->setLayout(finalLayout);

   QHBoxLayout* finalGradeLay = new QHBoxLayout;
   finalGradeLay->addWidget(finalDate);
   finalGradeLay->addWidget(finalDateLabel);
   finalGradeLay->addWidget(finalName);
   finalGradeLay->addWidget(finalLabel);
   finalGradeLay->addWidget(finalAdd);
   finals->setLayout(finalGradeLay);

   QHBoxLayout* finalResultsLayout = new QHBoxLayout;
   finalResultsLayout->addWidget(finalAvg);
   finalResultsLayout->addWidget(finalGrade);
   finalResultsLayout->addWidget(letterGrade);
   finalResultsLayout->addWidget(letterFinalLabel);
   finalResults->setLayout(finalResultsLayout);

   QHBoxLayout* commentFinalLayout = new QHBoxLayout;
   commentFinalLayout->addWidget(commentFinal);
   commentFinalBox->setLayout(commentFinalLayout);

   QVBoxLayout* mainFinalLayout = new QVBoxLayout;
   mainFinalLayout->addWidget(finalDesc);
   mainFinalLayout->addWidget(finals);
   mainFinalLayout->addWidget(finalResults);
   mainFinalLayout->addWidget(commentFinalBox);
   mainFinalLayout->addStretch(1);
   setLayout(mainFinalLayout);
}

void FinalTab::addFinalButton()
{
   double tempNum;
   QString temp, letter;
   temp = finalLabel->text();

   if (temp == "")
   {
      finalGrade->setText(tr("NA"));
      commentFinal->setText(tr("NA"));
      letterFinalLabel->setText(tr("NA"));
      return;
   }
   else
      finalGrade->setText(tr("%1 %").arg(temp));

   tempNum = temp.split(" ")[0].toInt();
   if (tempNum > 89)
      letter = "A";
   else if (tempNum < 90 && tempNum > 79)
      letter = "B";
   else if (tempNum < 80 && tempNum > 69)
      letter = "C";
   else if (tempNum < 70 && tempNum > 59)
      letter = "D";
   else
      letter = "F";

   if (tempNum >= 70)
   {
      commentFinal->setText(tr("You did good my son!"));
      commentFinal->append(tr("\nNow go check the home tab to see if you passed!"));
      commentFinal->append(tr("\nGood luck next semester, hahahahaha if you passed..."));
   }
   else
   {
      commentFinal->setText(tr("You done messed up A Aron! Take yo a** down to the home tab right now!"));
      commentFinal->append(tr("\nThere is still a chance you might have passed!"));
      commentFinal->append(tr("\nBut you still failed that final tho, Goodbye..."));
   }

   letterFinalLabel->setText(letter);
}


//This is the home section of tabs
//
//
//
HomeTab::HomeTab(QWidget *parent) : QWidget(parent)
{
   QGroupBox* homeDescr = new QGroupBox(tr("Instructions"));
   QTextEdit* homeInstr = new QTextEdit(tr("This is it! This determines if you pass or fail! Type the grades and percentages below from the tabs final grades and hit add to see final grade in class!"));
   homeInstr->setReadOnly(true);
   homeInstr->setFixedHeight(50);

   QGroupBox* homeworkTab = new QGroupBox(tr("Homework Input"));
   homeworkFinal = new QLineEdit;
   homeworkFinal->setFixedWidth(35);
   homeworkPerc = new QSpinBox;
   homeworkPerc->setFixedWidth(60);

   QGroupBox* testTab = new QGroupBox(tr("Test Input"));
   testFinal = new QLineEdit;
   testFinal->setFixedWidth(35);
   testPerc = new QSpinBox;
   testPerc->setFixedWidth(60);

   QGroupBox* partTab = new QGroupBox(tr("Participation Input"));
   partFinal = new QLineEdit;
   partFinal->setFixedWidth(35);
   partPerc = new QSpinBox;
   partPerc->setFixedWidth(60);

   QGroupBox* projectTab = new QGroupBox(tr("Project Input"));
   projectFinal = new QLineEdit;
   projectFinal->setFixedWidth(35);
   projectPerc = new QSpinBox;
   projectPerc->setFixedWidth(60);

   QGroupBox* finalTab = new QGroupBox(tr("Final Input"));
   finalFinal = new QLineEdit;
   finalFinal->setFixedWidth(35);
   finalPerc = new QSpinBox;
   finalPerc->setFixedWidth(60);

   QGroupBox* finalResultsBox = new QGroupBox(tr("Final Results"));
   QLabel* finalPanel = new QLabel(tr("Final Final Grade:"));
   finalFinalGrade = new QLineEdit;
   finalFinalGrade->setFixedWidth(85);
   QLabel* letterGrade = new QLabel(tr("Letter Grade:"));
   letterGradeFinal = new QLineEdit;
   letterGradeFinal->setFixedWidth(35);

   QGroupBox* commentSection = new QGroupBox(tr("Comments"));
   commentBox = new QTextEdit;
   commentBox->setReadOnly(true);


   QPushButton* gradeAdd = new QPushButton(tr("&Add"));
   gradeAdd->show();

   connect(gradeAdd, SIGNAL(clicked()), this, SLOT(addHomeButton()));

   QHBoxLayout* homeLayout = new QHBoxLayout;
   homeLayout->addWidget(homeInstr);
   homeDescr->setLayout(homeLayout);

   QFormLayout* homeworkLayout = new QFormLayout;
   homeworkLayout->addRow(tr("Homework Grade:"), homeworkFinal);
   homeworkLayout->addRow(tr("Homework Percentage:"), homeworkPerc);
   homeworkTab->setLayout(homeworkLayout);

   QFormLayout* testLayout = new QFormLayout;
   testLayout->addRow(tr("Test Grade:"), testFinal);
   testLayout->addRow(tr("Test Percentage:"), testPerc);
   testTab->setLayout(testLayout);

   QFormLayout* partLayout = new QFormLayout;
   partLayout->addRow(tr("Participation Grade:"), partFinal);
   partLayout->addRow(tr("Participation Percentage:"), partPerc);
   partTab->setLayout(partLayout);

   QFormLayout* projectLayout = new QFormLayout;
   projectLayout->addRow(tr("Project Grade:"), projectFinal);
   projectLayout->addRow(tr("Project Percentage:"), projectPerc);
   projectTab->setLayout(projectLayout);

   QFormLayout* finalLayout = new QFormLayout;
   finalLayout->addRow(tr("Final Grade:"), finalFinal);
   finalLayout->addRow(tr("Final Percentage:"), finalPerc);
   finalTab->setLayout(finalLayout);

   QHBoxLayout* finalResults = new QHBoxLayout;
   finalResults->addWidget(finalPanel);
   finalResults->addWidget(finalFinalGrade);
   finalResults->addWidget(letterGrade);
   finalResults->addWidget(letterGradeFinal);
   finalResultsBox->setLayout(finalResults);

   QHBoxLayout* commentLayout = new QHBoxLayout;
   commentLayout->addWidget(commentBox);
   commentSection->setLayout(commentLayout);

   QVBoxLayout* mainHomeLayout = new QVBoxLayout;
   mainHomeLayout->addWidget(homeDescr);
   mainHomeLayout->addWidget(homeworkTab);
   mainHomeLayout->addWidget(testTab);
   mainHomeLayout->addWidget(partTab);
   mainHomeLayout->addWidget(projectTab);
   mainHomeLayout->addWidget(finalTab);
   mainHomeLayout->addWidget(gradeAdd);
   mainHomeLayout->addWidget(finalResultsBox);
   mainHomeLayout->addWidget(commentSection);
   mainHomeLayout->addStretch(1);
   setLayout(mainHomeLayout);
}

void HomeTab::addHomeButton()
{
   double sum = 0, tempNum, tempNumPer;
   QString temp, tempPer, letter;

   for (int i = 0; i < 5; i++)
   {
      if (i == 0)
      {
         temp = homeworkFinal->text();
         tempPer = homeworkPerc->text();
      }
      else if (i == 1)
      {
         temp = testFinal->text();
         tempPer = testPerc->text();
      }
      else if (i == 2)
      {
         temp = partFinal->text();
         tempPer = partPerc->text();
      }
      else if (i == 3)
      {
         temp = projectFinal->text();
         tempPer = projectPerc->text();
      }
      else
      {
         temp = finalFinal->text();
         tempPer = finalPerc->text();
      }

      if (temp == "" || tempPer == "")
      {
         tempNum = 0;
         tempNumPer = 0;
      }
      else
      {
         tempNum = temp.split(" ")[0].toDouble();
         tempNumPer = tempPer.split(" ")[0].toInt();
      }

      sum += tempNum * (tempNumPer / 100.0);
   }

   if (sum > 89.5)
      letter = "A";
   else if (sum < 90 && sum > 79.5)
      letter = "B";
   else if (sum < 80 && sum > 69.5)
      letter = "C";
   else if (sum < 70 && sum > 59.5)
      letter = "D";
   else
      letter = "F";

   if (sum > 69.5)
   {
      commentBox->setText(tr("You did good my son!"));
      commentBox->append(tr("\nYou did it! You passed! I knew you had it in ya"));
      commentBox->append(tr("\nGood luck next semester, or maybe you are done, who cares you passed!"));
   }
   else
   {
      commentBox->setText(tr("You failed me boy..."));
      commentBox->append(tr("\nI dont even know what to say, because I didnt think you would get here..."));
      commentBox->append(tr("\nWell I guess you will see this class next year"));
   }


   QString charSum = QString::number(sum);
   finalFinalGrade->setText(tr("%1 %").arg(charSum));
   letterGradeFinal->setText(letter);
}
