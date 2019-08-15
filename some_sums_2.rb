# https://atcoder.jp/contests/abs/submissions/6916211
n, a, b = gets.split.map(&:to_i)
c = 0
1.upto(n) {|i| k = (i / 10000) % 10 + (i / 1000) % 10 + (i / 100) % 10 + (i / 10) % 10 + i % 10; c += i if a <= k and k <= b}
puts c
