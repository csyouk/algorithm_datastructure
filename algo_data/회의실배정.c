int main(void){

	int x;  // we want to find the minimum of x and y
	int y;
	int r;  // the result goes here 

	x = 20; y = 3;

	r = y ^ ((x ^ y) & -(x < y)); // min(x, y)
	printf("%d %d %d\n", r, x, y);

	r = x ^ ((x ^ y) & -(x < y)); // max(x, y)
	printf("%d %d %d\n", r, x, y);

}