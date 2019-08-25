n = gets.to_i
n.times do
  t, x, y = gets.split.map(&:to_i)
  distance = x + y
  if t < distance || (distance - t).odd?
    puts 'No'
    exit
  end
end

puts 'Yes'