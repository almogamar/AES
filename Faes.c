//we will try with no includes becouse we go hard af
#include <stdio.h>
/*---------------------defines-----------------------*/
#define ROUNDS 10 //key rounds 
#define ROW 4
/*---------------------defines-----------------------*/



/*---------------------consts------------------------*/
const int sub_box[] = { 0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
                        0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
                        0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
                        0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
                        0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
                        0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
                        0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
                        0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
                        0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
                        0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
                        0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
                        0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
                        0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
                        0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
                        0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
                        0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16 };

const int invert_sub_box[] = { 0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB,
                               0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB,
                               0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E,
                               0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25,
                               0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92,
                               0x6C, 0x70, 0x48, 0x50, 0xFD, 0xED, 0xB9, 0xDA, 0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84,
                               0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A, 0xF7, 0xE4, 0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06,
                               0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02, 0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B,
                               0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA, 0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73,
                               0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85, 0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E,
                               0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89, 0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B,
                               0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79, 0x20, 0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4,
                               0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31, 0xB1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xEC, 0x5F,
                               0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D, 0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF,
                               0xA0, 0xE0, 0x3B, 0x4D, 0xAE, 0x2A, 0xF5, 0xB0, 0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61,
                               0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26, 0xE1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D};

const int round_consts[] = {0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40,
                            0x80, 0x1B, 0x36, 0x6C, 0xD8, 0xAB, 0x4D, 0x9A,
                            0x2F, 0x5E, 0xBC, 0x63, 0xC6, 0x97, 0x35, 0x6A,
                            0xD4, 0xB3, 0x7D, 0xFA, 0xEF, 0xC5, 0x91, 0x39};

/*---------------------consts------------------------*/

/*----------------------func-------------------------*/

//helpers
void MatrixToArr(int matrix[ROW][ROW], int arr[]);
void arrToMatrix(int arr[], int matrix[ROW][ROW]);
void groupKeys(int matrix[][ROW], int keys[ROUNDS+1][ROW][ROW]);

int xor_time(int a);
void xor_arr(int a[], int b[], int ans[]);

void rot(int s[], int k);
void rev(int s[], int h, int l);
void deep_cop(int* a, int b[]);
void matrix_cop(int a[][ROW], int b[][ROW]);

//enc dec func
void expandKey(int key[], int word[ROW *(ROUNDS + 1)][ROW]);
void add_round_key(int state[][ROW], int key[][ROW]);

void shift_rows(int state[][ROW]);
void inv_shift_rows(int state[][ROW]);

void mix_col(int matrix[][ROW]);
void inv_mix_col(int s[][ROW]);

void mix_single_col(int col[]);

void sub_bytes(int s[][ROW]);
void invert_sub_bytes(int s[][ROW]);

void dec(int key[], int chipertext[]);
void enc(int key[], int text[]);
/*----------------------func-------------------------*/


int main()
{
    int key[] = {195, 44, 92, 166, 181, 128, 94, 12, 219, 141, 165, 122, 42, 182, 254, 92};
    int text[] = {209, 79, 20, 106, 164, 43, 79, 182, 161, 196, 8, 66, 41, 143, 18, 221};
    
    dec(key, text);
    int i = 0;

    for(i = 0; i < 16; i++)
    {
        printf("%c", (char)key[i]);
    }
    
    return 0;
}


//helpers
//this func will convert matrix to arr 
void MatrixToArr(int matrix[ROW][ROW], int arr[])
{
    int i = 0;
    int j = 0;

    for(i = 0; i < ROW; i++)
    {
        for(j = 0;j < ROW; j++)
        {
            arr[i * ROW + j] = matrix[i][j];
        }
    }
}

//this will do the oppsite
void arrToMatrix(int arr[], int matrix[ROW][ROW])
{
    int i = 0;
    int j = 0;
    int k = 0;

    for(i=0; i < ROW; i++)
    {
        for(j=0; j < ROW; j++)
        {
            matrix[i][j] = arr[k];
            k++;
        }
    }
}

//to group keys for easy use
void groupKeys(int matrix[][ROW], int keys[ROUNDS+1][ROW][ROW])
{
    int i = 0;
    int j = 0;
    int k = 0;

    for(i = 0; i < ROUNDS+1; i++)
    {
        for(j = 0; j < ROW; j++)
        {
            for(k = 0; k < ROW; k++)
            {
                keys[i][j][k] = matrix[(i * ROW) + j][k];
            }
        }
    }
}

//xor help 
int xor_time(int a)
{
    int shift = a << 1;

    //if a is not 0x80(128)
    if(a & 0x80)
    {
        return ((shift ^ 0x1B) & 0xFF);
    }
    
    return shift;

}

void xor_arr(int a[], int b[], int ans[])
{
    int i = 0;

    for(i = 0; i < ROW; i++)
    {
        ans[i] = a[i] ^ b[i];
    }
}


//helps with shift rows to make it O(2n) and mudolar
void rot(int s[], int k)
{
    int size = ROW;

    rev(s, 0, size-k-1);
    rev(s, size-k, size-1);
    rev(s, 0, size-1);
}

//helps prev func
void rev(int s[], int l, int h)
{
    while(h > l)
        {
            //just simple fliping with o(1) aux space couse we go hard 
            s[h] += s[l];
            s[l] = s[h] - s[l];
            s[h] = s[h] - s[l];
            h--;
            l++;
        }
}

//problems with the rot func on int*
void deep_cop(int* a, int b[])
{
    int i = 0;
    
    for(i = 0; i < ROW; i++)
    {
        b[i] = a[i];
    }

}

//copy matrix
void matrix_cop(int a[][ROW], int b[][ROW])
{
    int i = 0;
    int j = 0;

    for(i = 0; i < ROW; i++)
    {
        for(j = 1; j < ROW; j++)
        {
            a[i][j] = b[i][j];
        }
    }
}

//enc dec func
void expandKey(int key[], int word[ROW *(ROUNDS + 1)][ROW])
{
    int i = ROW;
    int j = 0;

    //will use it just to make stuff easier
    int last[ROW];
    int tmp;

    arrToMatrix(key, word);
    
    for(i = ROW; i < ROW *(ROUNDS + 1); i++)
    {
        deep_cop(word[i-1], last);
        
        if(i % ROW == 0)
        {
            //just a rotation / a bug in rot func
            tmp = last[0];
            
            for(j = 0; j < ROW -1; j++)
            {
                last[j] = last[j+1];
            }

            last[j] = tmp;

            for(j = 0; j < ROW; j++)
            {
                //maybe i will split sbox func so i can use it also here
                last[j] = sub_box[last[j]];
            }

            last[0] ^= round_consts[i/ROW];
            //printf("arr - %d i - %d, r-%d\n",last[0],i/ROW, round_consts[i/ROW]);
        }
        
        xor_arr(word[i-ROW], last, word[i]);

    }
    
}

void add_round_key(int state[][ROW], int key[][ROW])
{
    int i = 0;
    int j = 0;
    
    for(i=0; i < ROW; i++)
    {
        for(j=0; j < ROW; j++)
        {
            state[i][j] = state[i][j] ^ key[i][j];
        }
    }
}

//just shift each row by it index
void shift_rows(int state[][ROW])
{
    int i = 1;
    int j = 0;

    int temp[ROW][ROW];

    //rotate
    for(i = 0; i < ROW; i++)
    {
        for(j = 1; j < ROW; j++)
        {
            temp[i][j] = state[(j+i) % ROW][j];
        }
    }
    matrix_cop(state, temp);
}

//the same but 3 more times
void inv_shift_rows(int state[][ROW])
{
    int i = 1;
    int j = 0;

    int temp[ROW][ROW];

    //rotate
    for(i = 0; i < ROW; i++)
    {
        for(j = 1; j < ROW; j++)
        {
            temp[(j+i) % ROW][j] = state[i][j];
        }
    }
    matrix_cop(state, temp);
}

//cool mix col shit
void mix_single_col(int col[])
{
    int i = 0;
    
    int fTmp = col[0];
    int first = col[0];

    for(i=1; i < ROW; i++)
    {
        fTmp ^= col[i];
    }

    for(i = 0; i < ROW - 1; i++)
    {
        col[i] ^= fTmp ^ xor_time(col[i] ^ col[i+1]);
    }

    col[i] ^= fTmp ^ xor_time(col[i] ^ first);
}

//mix all
void mix_col(int matrix[][ROW])
{
    int i = 0;
    
    for(i = 0; i < ROW; i++)
    {
        mix_single_col(matrix[i]);
    }
}

//xor trick couse why not 
void inv_mix_col(int s[][ROW])
{
    int i = 0;
    int j = 0;
    //for better readablity 
    int u = 0;
    int v = 0;

    for(i = 0; i < ROW; i++)
    {
        //need to be changed for more modular coding(know only suppurt aes128)
        u = xor_time(xor_time(s[i][0] ^ s[i][2]));
        v = xor_time(xor_time(s[i][1] ^ s[i][3]));
        
        for(j = 0; j < ROW; j++)
        {
            //to skip modulo check 
            //first one will be even and second will be odd(no reading error becouse the matrix is always even)
            s[i][j++] ^= u;
            s[i][j] ^= v;
        }
    } 
    mix_col(s);
}


//sub bytes, its a global table only one len(128) atm
void sub_bytes(int s[][ROW])
{
    int i = 0;
    int j = 0;

    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < ROW; j++)
        {
            s[i][j] = sub_box[s[i][j]];
        }
    }
}

//invert
void invert_sub_bytes(int s[][ROW])
{
    int i = 0;
    int j = 0;

    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < ROW; j++)
        {
            s[i][j] = invert_sub_box[s[i][j]];
        }
    }
} 

void dec(int key[], int chipertext[])
{
    //one odd round so we do it sepratliy
    int i = ROUNDS -1;
    
    int tmpKeys[ROW *(ROUNDS + 1)][ROW];
    int keys[ROUNDS+1][ROW][ROW];
    int state[ROW][ROW];

    int plaintext[ROW*ROW];

    expandKey(key, tmpKeys);
    
    groupKeys(tmpKeys, keys);
    
    arrToMatrix(chipertext, state);

    add_round_key(state, keys[ROUNDS]);

    
    for(i = ROUNDS-1; i > 0; i--)
    {
        inv_shift_rows(state);
        invert_sub_bytes(state);
        add_round_key(state, keys[i]);
        inv_mix_col(state);
    }

    inv_shift_rows(state);
    invert_sub_bytes(state);
    add_round_key(state, keys[i]);

    MatrixToArr(state, key);
}


void enc(int key[], int text[])
{
    //one odd round so we do it sepratliy
    int i = 0;
    
    int tmpKeys[ROW *(ROUNDS + 1)][ROW];
    int keys[ROUNDS+1][ROW][ROW];
    int state[ROW][ROW];

    int ciphertext[ROW*ROW];

    expandKey(key, tmpKeys);
    
    groupKeys(tmpKeys, keys);
    
    arrToMatrix(text, state);
    
    add_round_key(state, keys[0]);

    for(i = 0; i < ROUNDS -1; i++)
    {
        sub_bytes(state);
        shift_rows(state);
        mix_col(state);
        add_round_key(state, keys[i]);
    }

    sub_bytes(state);
    shift_rows(state);
    add_round_key(state, keys[i]);

    MatrixToArr(state, key);

}
