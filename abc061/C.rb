# https://atcoder.jp/contests/abc061/tasks/abc061_c


N, K = gets.split.map(&:to_i)
as = Array.new(N)
bs = Array.new(N)
N.times do |i|
  as[i], bs[i] = gets.split.map(&:to_i)
end

puts ans
