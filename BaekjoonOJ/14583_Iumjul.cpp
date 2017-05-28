#include <stdio.h>
#include <math.h>

int main() {
	double w, h, theta;

	scanf("%lf %lf", &w, &h);
	theta = atan(h / w);

	printf("%.2lf %.2lf", w / (2 * cos(theta / 2)), (h - w*tan(theta / 2))*cos(theta / 2));
}