這是用C寫的 Karatsuba 大數乘法

A∗B
=(w ∗ 10^n/2 + x) ∗ ( y ∗ 10^n/2 + z)

=wy ∗ 10^n + (wz + xy) ∗ 10^n/2 + xz

=wy ∗ 10^n + [(w + x) ∗ (y + z) − wy − xz] ∗ 10^n/2 + xz


=> f(n) = 3 f(n/2) + O(n)

=> 根據master theorem


=> f(n) = O(n^lg3)


------code 描述------

功能:
  根據讀入兩個長正整數，算出這兩個的乘積


kmul就是Karatsuba的乘法
1. 先將兩個大數都切一半
2. 如果其中一個目標的大數變成一位數了，就把結果用一般的乘法算出來
3. 算出透過 三個 kmul遞迴算出 wy, xy, r = (w + x) * (y + z)
4. 將結果傳回上層
