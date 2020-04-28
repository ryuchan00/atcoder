# https://atcoder.jp/contests/abc073/tasks/abc073_d


N, M, R = gets.split.map(&:to_i)
rs = gets.split.map(&:to_i)
As = Array.new(M)
Bs = Array.new(M)
Cs = Array.new(M)
M.times do |i|
  As[i], Bs[i], Cs[i] = gets.split.map(&:to_i)
end

puts ans
