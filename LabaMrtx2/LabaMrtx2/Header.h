#pragma once
void InputMtrSize(int32_t&, int32_t&);
void InputElementsInMtr(double**&, int32_t, int32_t);
void InputBorders(int32_t& a, int32_t&);
void FillMtrWithRandomNumbers(double**&, int32_t, int32_t);
void ChooseMethod(double**&, int32_t, int32_t);
void FindFirstRowsWithZero(double**&, int32_t, int32_t);
bool IsMinNumInRow(double**&, int32_t, double, int32_t);
bool IsMaxNumInColl(double**&, int32_t, double, int32_t);
void FindCoordsOfAllSaddlePoints(double**&, int32_t, int32_t);
void FindCollOfMaxElementInMtr(double**&, int32_t, int32_t, int32_t&);
void FindRowOfMinElementInMtr(double**&, int32_t, int32_t, int32_t&);
void CountDotProduct(double**&, int32_t, int32_t);
int64_t FindFirstIntegerElementInMtr(double**&, int32_t, int32_t);
void FindMinIntegerElementInMtr(double**&, int32_t, int32_t, int64_t&);
void FindFirstMinIntegerElementInMtr(double**&, int32_t, int32_t);

