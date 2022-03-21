# pragma once
//====== ������� 1 ======
// (��� ������� ����� n)
//����������� ������ �� X � Y
void dcopy(int n, const double* X, double* Y);
//�������� ������� ���������� �������� X � Y
void dswap(int n, double* X, double* Y);
//��������� ������ X �� ����������� alpha
void dscal(int n, double alpha, double* X);
//��������� � ������� Y ������ X, ���������� �� ����������� alpha
void daxpy(int n, double alpha, const double* X, double* Y);
//��������� ��������� ������������ �������� X � Y
double ddot(int n, const double* X, const double* Y);
//====== ������� 2 ======
//��������� ������ (alpha*A*X + beta*Y) ����� m, � �������� ��� � Y
//����� A �- ������� ������� m �� n, X �- ������ ����� n, � Y �- ������ ����� m
void dgemv(
	int m, int n,
	double alpha, const double* A, const double* X,
	double beta, double* Y
);
//��������� ������� (alpha*X*Yt + A) � �������� � � A
//����� Yt �- ��� ����������������� ������ Y, �� ���� ���������� ��� ������-������
// A �- ������� ������� m �� n, X �- ������ ����� m, � Y �- ������ ����� n
void dger(
	int m, int n,
	double alpha, const double* X, const double* Y,
	double* A
);
//====== ������� 3 ======
//��������� ������� (alpha*A*B + beta*C) � �������� � � C
//����� A �- ������� ������� m �� k, B �- ������� ������� k �� n,
// C �- ������� ������� m �� n
void dgemm(
	int m, int n, int k,
	double alpha, const double* A, const double* B,
	double beta, double* C
);