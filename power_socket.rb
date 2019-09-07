a, b = gets.split.map(&:to_i)
kuchi = 1
tap = 0
while kuchi < b
  kuchi -= 1
  kuchi += a
  tap += 1
end
puts tap