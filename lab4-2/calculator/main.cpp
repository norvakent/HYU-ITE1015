#include "my_func.h"

int main() {
	while (true) {
		float num[2];
		char oper;
		float result;
		get_number(1, num[0]);
		get_number(2, num[1]);
		get_operator(oper);
		if(oper == '+') result = sum(num[0], num[1]);
		else if (oper == '-') result = sub(num[0], num[1]);
		else if (oper == '*') result = mul(num[0], num[1]);
		else if (oper == '^') result = pow(num[0], num[1]);
		else if (oper == '/') {
			if (num[1] == 0) {
				show_error();
				continue;
			}
			result = div(num[0], num[1]);
		}
		else {
			show_error();
			continue;
		}
		show_result(num[0], num[1], oper, result);
	}
}
