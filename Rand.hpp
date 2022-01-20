/**
 *  <p>This cpp file is used to achieve Linear Congruential Method</p>
 *
 *  <p> A linear congruential generator (LCG) is an algorithm that yields
 *      a sequence of pseudo-randomized numbers calculated with a discontinuous
 *      piecewise linear equation. The method represents one of the oldest and
 *      best-known pseudorandom number generator algorithms. The theory behind
 *      them is relatively easy to understand, and they are easily implemented
 *      and fast, especially on computer hardware which can provide modular
 *      arithmetic by storage-bit truncation.
 *  </p>
 *
 *  <p>
 *      中文介绍：
 *      线性同余方法（LCG）是个产生伪随机数的方法。
 *      它是根据递推公式：RandSeed = (A * RandSeed + B) % M .其中 A , B , M 是产生器设定的常数。
 *      LCG的周期最大为 M，但大部分情况都会少于 M 。要令LCG达到最大周期 ，应符合以下条件：B , M 互质；
 *  </p>
 *  <p>M 的所有质因数都能整除 A-1；</p>
 *  <p>若 M 是 4 的倍数，A-1 也是；</p>
 *  <p>A , B , RandSeed 都比 M 小；</p>
 *  <p>A , B 是正整数。</p>
 *
 *
 *  <p>Created by BowenDeng on 2021/10/31.</p>
 */

#ifndef UNTITLED4_LGC_METHOD_H
#define UNTITLED4_LGC_METHOD_H

static unsigned int prngState = 0;

/*********************************************************************
 * @fn      _rand
 *
 * @brief   Get a random value
 *
 * @param   void
 *
 * @return  Random value
 */
unsigned int jPPRand() {

    unsigned int value;

    int para_A = 1103515245, para_B = 12345;

    //Use a linear congruential generator (LCG) to update the state of the PRNG
    prngState *= para_A;
    prngState += para_B;
    value = (prngState >> 16) & 0x07FF;

    prngState *= para_A;
    prngState += para_B;
    value <<= 10;
    value |= (prngState >> 16) & 0x03FF;

    prngState *= para_A;
    prngState += para_B;
    value <<= 10;
    value |= (prngState >> 16) & 0x03FF;

    //Return the random value
    return value;
}


/*********************************************************************
 * @fn      rand_range
 *
 * @brief   Get a random value in the specified range
 *
 * @param   min Lower bound
 *
 * @param   max Upper bound
 *
 * @return  Random value in the specified range
 */
unsigned int jPPRandRange(unsigned int min, unsigned int max) {

    unsigned int value;

    //Valid parameters?
    if (max > min) {
        //Pick up a random value in the given range
        value = min + (jPPRand() % (max - min + 1));
    } else {
        //Use default value
        value = min;
    }

    //Return the random value
    return value;
}

#endif //UNTITLED4_LGC_METHOD_H