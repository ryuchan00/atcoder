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
# https://atcoder.jp/contests/abc142/submissions/7769166