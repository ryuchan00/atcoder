def init
  $n = $stdin.gets.chomp.split(" ").map(&:to_i)
  $line = %w()
  while line = gets
    $line.push(line.chomp.split(' ').map(&:to_i))
  end
end

init

def plan
  $line.each do |l|
    return if l[0] < l[1] + l[2]
    return unless ((l[0] - (l[1] + l[2])) % 2).zero?
  end
  true
end

puts plan ? 'Yes' : 'No'