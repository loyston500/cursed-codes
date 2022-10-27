#include <stdio.h>
#include <string.h>

int uncurse(char *arg){
	while(*arg){
		putc(*arg & (1 << 010) ? ~(*arg) : (*arg), stdout);
		arg++;
	}
	return *arg;
}

int main(){
	long long msg[2] = {0x9077209093936548, 0xf521649372};
	char      str[16];
	memcpy(str  , msg  , 8);
	memcpy(str+8, msg+1, 8);
	return uncurse(str);
}
