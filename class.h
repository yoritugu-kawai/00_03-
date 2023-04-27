#pragma once
struct   Matrix4x4 {
	float m[4][4];
};
struct Vector3 {
	float x;
	float y;
	float z;


};
Matrix4x4 MakeTranslateMatrix(const Vector3& translate);
Matrix4x4 MakeScaleMatrix(const Vector3 scale);
Vector3 Transform(const Vector3 vector, const Matrix4x4 matrix);
void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* laber);
void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label);

static const int  kCHei = 20;
static const int  kCWid = 60;
