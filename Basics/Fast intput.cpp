/* Fastest way to read ints is this it is much faster than scanf
   and cin So use this 
   
   For fast output printf is the best

*/
int readInt () {
bool minus = false; int result = 0;char ch;ch = getchar();
while (true) {if (ch == '-') break;if (ch >= '0' && ch <= '9') break;ch = getchar();}
if (ch == '-') minus = true; else result = ch-'0';while (true) {ch = getchar(); 
if (ch < '0' || ch > '9') break;result = result*10 + (ch - '0');}
if (minus)return -result;else return result;}