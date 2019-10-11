require 'prime'
A, B = gets.split.map(&:to_i)
b = [A, B].max
s = [A, B].min
c = 1
Prime.each(s / 2).each do |i|
  c += 1 if (b % i).zero? && (s % i).zero?
end
puts c

# 参考コード
# ref:https://atcoder.jp/contests/abc142/submissions/7769166
str = gets.split
A, B = str[0].to_i, str[1].to_i

# Integer#gcdは最大公約数を求める
c = A.gcd(B)
# 最小の異なる素になる整数
a = 1
b = 3

# 偶数の場合は、2が素になるため、1を追加する
a = c % 2 == 0 ? a + 1 : a
# cが奇数になるまで
while c % 2 == 0
  c /= 2
end
# 10 ** 6 は最大公約数は最大でもx / 2であるため(問題文は10 ** 12 の範囲を指定している)
while c > 2 && b < 10 ** 6
  a = c % b == 0 ? a + 1 : a
  while c % b == 0
    c /= b
  end
  b += 2
end
if c != 1
  a += 1
end
puts a

# ref:https://atcoder.jp/contests/abc142/submissions/7775743
a, b = gets.split.map(&:to_i)

# 1を含む最大公約数のロジック
def my_gcd(x, y)
  return x if y.zero?

  my_gcd(y, x % y)
end

def my_prime_division(n)
  res = Hash.new(0)
  i = 2
  while i * i <= n
    if n % i != 0
      i += 1
      next
    end

    while n % i == 0
      n /= i
      res[i] += 1
    end
    i += 1
  end
  if n != 1
    res[i] += 1
  end
  res
end

# require 'prime'
# puts Prime.prime_division(a.gcd(b)).size + 1
puts my_prime_division(my_gcd(a, b)).keys.size + 1
