n = gets.to_i
b = gets.split.map(&:to_i)
sum = b[0]
n.times do |i|
  if b[i + 1].nil?
    sum += b[i]
    break
  end
  if b[i] > b[i +1]
    sum += b[i +1]
  else
    sum += b[i]
  end
end
puts sum