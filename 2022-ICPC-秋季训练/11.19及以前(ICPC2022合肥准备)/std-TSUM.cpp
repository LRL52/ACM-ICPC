#ifndef Polynomial_Class
    #define Polynomial_Class
    #include <array>
    #include <iostream>
    #include <algorithm>

    using namespace std;

    __int128 fast_pow(__int128 base,__int128 exp,__int128 prime)
    {
        __int128 result;
        for(result=1;exp;exp&1?result=result*base%prime:true,base=base*base%prime,exp>>=1);
        return result;
    }
    unsigned int ceil_binary(unsigned int org_size)
    {
        while(org_size&org_size-1)
            org_size+=org_size&-org_size;
        return org_size;
    }
    unsigned int log_binary(unsigned int org_size)
    {
        unsigned int result=0;
        while(org_size)
            org_size>>=1,result++;
        return result-1;
    }
    inline __int128 inverse(__int128 num,__int128 prime)
    {
        return fast_pow(num,prime-2,prime);
    }

namespace Polynomial
{
    typedef long long term_type;
    typedef size_t size_type;

    const term_type prime=79164837199873,proot=5;
    const term_type proot_inv=fast_pow(proot,prime-2,prime);

    template<size_type polysz>
    using polynomial=array<term_type,polysz>;

    array<unsigned int,131072> binary_rev;
    polynomial<131072> _mult_tmpa,_mult_tmpb;

	long long modulos_mult(long long a,long long b,long long prime)
	{
		return (a*(b%100000)%prime+a*(b/100000%100000)%prime*100000%prime+a*(b/10000000000ll)%prime*100000%prime*100000%prime)%prime;
	}
    void init_binrev(int cnt_term)
    {
        size_type lim=ceil_binary(cnt_term);
        size_type tmp=log_binary(lim);
        for(size_type i=1;i<lim;i++)
            binary_rev[i]=(binary_rev[i>>1]>>1)|((i&1)<<(tmp-1));
    }
    template<size_type polysz>
    void NTT(int cnt_term,polynomial<polysz>& plnmal,int type)
    {
        for(int i=0;i<cnt_term;i++)
            if(i<binary_rev[i])
                swap(plnmal[i],plnmal[binary_rev[i]]);
        for(int mid=1;mid<cnt_term;mid<<=1)
        {
            long long omega=fast_pow(type==1?proot:proot_inv,(prime-1)/(mid<<1),prime);
            for(int right_l=mid<<1,i=0;i<cnt_term;i+=right_l)
            {
                long long proot_pow=1;
                for(int j=0;j<mid;j++,proot_pow=modulos_mult(proot_pow,omega,prime))
                {
                    long long x=plnmal[i+j],y=modulos_mult(proot_pow,plnmal[i+j+mid],prime);
                    plnmal[i+j]=(x+y)%prime,plnmal[i+j+mid]=(x-y+prime)%prime;
                }
            }
        }
        if(type==-1)
        {
            __int128 inverse=fast_pow(cnt_term,prime-2,prime);
            for(int i=0;i<cnt_term;i++)
                plnmal[i]=plnmal[i]*inverse%prime; 
        }
    }
    template<size_type polysz1,size_type polysz2>
    void mult(int cntterm_a,int cntterm_b,const polynomial<polysz1>& a_tmp,const polynomial<polysz1>& b_tmp,polynomial<polysz2>& ans)
    {
        for(int i=0;i<cntterm_a;i++)
            _mult_tmpa[i]=a_tmp[i];
        for(int i=0;i<cntterm_b;i++)
            _mult_tmpb[i]=b_tmp[i];
        int ceil_cnt=1,len_ceil=0;
        while(ceil_cnt<cntterm_a+cntterm_b)
            ceil_cnt<<=1,len_ceil++;
        for(int i=cntterm_a;i<ceil_cnt;i++)
            _mult_tmpa[i]=0;
        for(int i=cntterm_b;i<ceil_cnt;i++)
            _mult_tmpb[i]=0;
        NTT(ceil_cnt,_mult_tmpa,1),NTT(ceil_cnt,_mult_tmpb,1);
        for(int i=0;i<ceil_cnt;i++)
            ans[i]=modulos_mult(_mult_tmpa[i],_mult_tmpb[i],prime);
        NTT(ceil_cnt,ans,-1);
        for(int i=cntterm_a+cntterm_b;i<ceil_cnt;i++)
            ans[i]=0;
    }
}
#endif

using namespace std;
using namespace Polynomial;

polynomial<131072> poly_inital,poly_invalid,final_ans;

ostream& operator<<(ostream& os,__int128 num)
{
    if(num>=10)
        os<<num/10;
    return os<<(int)(num%10);
}

int main(int argc,char* argv[],char* envp[])
{
	init_binrev(131072);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int cnt,tmp;
	cin>>cnt;
	while(cnt--)
		cin>>tmp,poly_inital[tmp+20000]++;
	mult(40001,40001,poly_inital,poly_inital,final_ans);
	mult(40001,80001,poly_inital,final_ans,final_ans);
	for(int i=0;i<=40000;i++)
		poly_invalid[2*i]=3*poly_inital[i];
	mult(40001,80001,poly_inital,poly_invalid,poly_invalid);
	for(int i=0;i<=40000;i++)
		poly_invalid[3*i]-=2*poly_inital[i];
	for(int i=0;i<=120000;i++)
		final_ans[i]=(final_ans[i]-poly_invalid[i])/6,final_ans[i]&&(cout<<i-60000<<" : "<<final_ans[i]<<'\n');
	return 0;
}