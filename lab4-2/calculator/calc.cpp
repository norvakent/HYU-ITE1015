float sum(float a, float b) {
	return a + b;
}

float sub(float a, float b) {
	return a - b;
}

float mul(float a, float b) {
	return a * b;
}

float div(float a, float b) {
	return a / b;
}

float pow(float a, int b) {
	float result = 1;
	if (b >= 0) for (int i = 0; i < b; i++) result *= a;
	else for (int i = 0; i < -b; i++) result /= a;
	return result;
}
