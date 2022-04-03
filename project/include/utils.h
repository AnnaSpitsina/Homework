#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#define FILENAME "transaction.dat"


struct masterRecord {
  int Number;
  char Name[20];
  char Surname[20];
  char addres[30];
  char TelNumber[15];
  double indebtedness;
  double credit_limit;
  double cash_payments;
};
typedef struct masterRecord Data;

void masterWrite(FILE* ofPTR, Data Client);
void transactionWrite(FILE* ofPTR, Data transfer);
void FuncBlackRecord(FILE* ofPTR,
                 FILE* ofPTR_2,
                 FILE* blackrecord,
                 Data client_data,
                 Data transfer);

#endif  // UTILS_H
