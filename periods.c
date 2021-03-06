/*
En fil innehållande en uppsättning olika sinusperioder som används för att
uppdatera PWM duty cycle.
*/
const unsigned int PERIODS[2][64] = {
    {
        0x80,0x8c,0x98,0xa5,0xb0,0xbc,0xc6,0xd0,
        0xda,0xe2,0xea,0xf0,0xf5,0xfa,0xfd,0xfe,
        0xff,0xfe,0xfd,0xfa,0xf5,0xf0,0xea,0xe2,
        0xda,0xd0,0xc6,0xbc,0xb0,0xa5,0x98,0x8c,
        0x80,0x73,0x67,0x5a,0x4f,0x43,0x39,0x2f,
        0x25,0x1d,0x15,0xf,0xa,0x5,0x2,0x1,
        0x0,0x1,0x2,0x5,0xa,0xf,0x15,0x1d,
        0x25,0x2f,0x39,0x43,0x4f,0x5a,0x67,0x73
    },
    {
        0x800,0x8c8,0x98f,0xa52,0xb0f,0xbc5,0xc71,0xd12,
        0xda7,0xe2e,0xea6,0xf0d,0xf63,0xfa7,0xfd8,0xff5,
        0xfff,0xff5,0xfd8,0xfa7,0xf63,0xf0d,0xea6,0xe2e,
        0xda7,0xd12,0xc71,0xbc5,0xb0f,0xa52,0x98f,0x8c8,
        0x800,0x737,0x670,0x5ad,0x4f0,0x43a,0x38e,0x2ed,
        0x258,0x1d1,0x159,0xf2,0x9c,0x58,0x27,0xa,
        0x0,0xa,0x27,0x58,0x9c,0xf2,0x159,0x1d1,
        0x258,0x2ed,0x38e,0x43a,0x4f0,0x5ad,0x670,0x737
    }
};
