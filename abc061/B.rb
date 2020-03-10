# https://atcoder.jp/contests/abc061/tasks/abc061_b


N, M = gets.split.map(&:to_i)
as = Array.new(M)
bs = Array.new(M)
M.times do |i|
  as[i], bs[i] = gets.split.map(&:to_i)
end

puts ans
