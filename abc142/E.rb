N, M = gets.split.map(&:to_i)
as = Array.new(1)
bs = Array.new(1)
1.times do |i|
  as[i], bs[i] = gets.split.map(&:to_i)
end
aM, bM = gets.split.map(&:to_i)

puts ans
