#include<iostream>
#include<cmath>
using namespace std;
int modpow(int a,int b,int mod)				//power function using modular multiplicative inverse
{											//for e.g., (a^b) modulo (mod)
    int product,pseq;
    product=1;
    pseq=a%mod;
    while(b>0)
    {
        if(b&1)
            product=(product*pseq)%mod;
        pseq=(pseq*pseq)%mod;
        b>>=1;
    }
    return product;
}
int gcd(int a, int b){						//function for Greatest Common Divisor(GCD)
	int temp;
	while(1){
		temp=a%b;
		if(temp==0)
			return b;
		a=b;
		b=temp;
	}
}
int main(){
	int p=17, q=11;		//change 'p' and 'q' to required prime numbers
	int n=p*q;
	int e=2;
	int phi=(p-1)*(q-1);
	while(e<phi){
		if(gcd(e, phi)==1)
			break;
		else
			e++;
	}
	int k=1;
	int d;
	while(1){
		d=(1+(k*phi));
		if(d%e==0){
			d/=e;
			break;
		}
		else{
			k++;
		}
	}
	int msg;
	cout<<"\nEnter Message data: ";		cin>>msg;
	int c=modpow(msg, e, n);
	cout<<"\nEncrypted data: "<<c;
	int m=modpow(c, d, n);
	cout<<"\nMessage data: "<<m;
	return 0;
}
