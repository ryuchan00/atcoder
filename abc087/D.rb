N, M = gets.split.map(&:to_i)
Ls = Array.new(M)
Rs = Array.new(M)
Ds = Array.new(M)
M.times do |i|
  Ls[i], Rs[i], Ds[i] = gets.split.map(&:to_i)
end

puts ans
