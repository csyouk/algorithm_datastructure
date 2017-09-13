// c워크샾 심화
#if 0

int main(void){

	// 1
#if 0
	signed int a = 0xffffffff;
	unsigned int b = -1;
	printf("%d, %u, %x\n", a, a, a);
	printf("%d, %u, %x\n", b, b, b);
#endif

	// 2
#if 0
	signed char sc = 0xff;
	unsigned char uc = -1;
	char c = uc;
	printf("%x, %x, %x", sc, uc, c);

#endif


	// 3
#if 0
	signed int a = -1;
	unsigned int b = a;
	printf("%d, %u, %x\n", a, a, a);
	printf("%d, %u, %x\n", b, b, b);

#endif

	// 4
#if 0
	signed char sc = 127;
	unsigned char uc = 1;
	char c = sc + uc;
	printf("%d", c);

#endif

	// 5
#if 0
	short ss = 65535 - 1;
	printf("%hd, %hu, %hx\n", ss, ss, ss);

#endif

	// 6
#if 0
	float a = 3.25;
	double b = 3.25;
	if (a == b) printf("true");
	else printf("false");

#endif

	// 7
#if 0
	float f = 3.625f;
	double d = 3.625;
	printf("%#x, %#x", f, d);
#endif

	// 14
#if 0
	signed int si = 0x12345678;	unsigned int ui = 0x12345678;
	signed short ss; 		unsigned short us;
	ss = si;	                      us = si;
	printf("%x, %x\n", ss, us);
	ss = ui;	us = ui;
	printf("%x, %x\n", ss, us);

#endif

	// 15
#if 0
	unsigned char uc = 0xff;
	signed char sc = 0xff;
	int a, b;
	a = uc + 1;	b = sc + 1;
	printf("%d, %d\n", a, b);

#endif

	// 16
#if 0
	signed char  sc = -1;
	unsigned char  uc = -1;
	printf(" %x %x ", sc + sizeof(char), uc + sizeof(char));

#endif

	// 17
#if 0
	double d = 3.5;
	float f;
	f = (float)d + (float)0.5;
	printf("%f\n", f);

#endif

	// 18
#if 01
	signed int a = -1;
	unsigned char b = -1;
	if (a<b) printf("unsigned \n");
	else if (a>b) printf("singed\n");
	else printf("same");

#endif



	return 0;
}

#endif