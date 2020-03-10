# https://atcoder.jp/contests/abc061/tasks/abc061_d


N, M = gets.split.map(&:to_i)
as = Array.new(M)
bs = Array.new(M)
cs = Array.new(M)
M.times do |i|
  as[i], bs[i], cs[i] = gets.split.map(&:to_i)
end

puts ans
