#include "class.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include <cmath>
#include<cassert>

Matrix4x4 MakeTranslateMatrix(Vector3 translate) {
	Matrix4x4 result;
	result.m[0][0] = 1.0f;
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;
	result.m[0][3] = 0.0f;

	result.m[1][0] = 0.0f;
	result.m[1][1] = 1.0f;
	result.m[1][2] = 0.0f;
	result.m[1][3] = 0.0f;

	result.m[2][0] = 0.0f;
	result.m[2][1] = 0.0f;
	result.m[2][2] = 1.0f;
	result.m[2][3] = 0.0f;


	result.m[3][0] = translate.x;
	result.m[3][1] = translate.y;
	result.m[3][2] = translate.z;
	result.m[3][3] = 1.0f;


	return result;
}


Vector3 Transform(const Vector3 vector, const Matrix4x4 matrix) {
	Vector3 result;

	result.x = (vector.x * matrix.m[0][0]) + (vector.y * matrix.m[1][0])
		+ (vector.z * matrix.m[2][0]) + (1.0f * matrix.m[3][0]);

	result.y = (vector.x * matrix.m[0][1]) + (vector.y * matrix.m[1][1])
		+ (vector.z * matrix.m[2][1]) + (1.0f * matrix.m[3][1]);

	result.z = (vector.x * matrix.m[0][2]) + (vector.y * matrix.m[1][2])
		+ (vector.z * matrix.m[2][2]) + (1.0f * matrix.m[3][2]);

	float w = (vector.x * matrix.m[0][3]) + (vector.y * matrix.m[1][3]) + (vector.z * matrix.m[2][3]) + (1.0f * matrix.m[3][3]);


	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	result.z /= w;

	return result;


}

Matrix4x4 MakeScaleMatrix(const Vector3 scale) {
	Matrix4x4 result;


	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result.m[i][j] = 0.0f;
			if (result.m[i == 0][j == 0])
			{
				result.m[0][0] = scale.x;
			}if (result.m[i == 1][j == 1])
			{
				result.m[1][1] = scale.y;
			}
			if (result.m[i == 2][j == 2])
			{
				result.m[2][2] = scale.z;
			}
			if (result.m[i == 3][j == 3])
			{
				result.m[3][3] = 1.0f;
			}
		}


	}

	return result;
}

void VectorScreenPrintf(int x, int y, const Vector3 vector, const char* label) {
	Novice::ScreenPrintf(x + kCWid * 0, y, "%6.02f", vector.x);
	Novice::ScreenPrintf(x + kCWid * 1, y, "%6.02f", vector.y);
	Novice::ScreenPrintf(x + kCWid * 2, y, "%6.02f", vector.z);

	Novice::ScreenPrintf(x + kCWid * 4, y, "%s", label);

}


void MatrixScreenPrintf(int x, int y, const Matrix4x4 matrix, const char* label) {
	for (int row = 0; row < 4; ++row) {
		for (int column = 0; column < 4; ++column) {
			Novice::ScreenPrintf(x, y, "%s", label);
			Novice::ScreenPrintf(x + column * kCWid, y + (row + 1) * kCHei, "%6.02f", matrix.m[row][column]);
		}
	}
}

