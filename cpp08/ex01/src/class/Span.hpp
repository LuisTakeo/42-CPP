#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <iterator>

class Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_nums;
		Span();

	public:
		Span(unsigned int n);
		Span(const Span &src);
		~Span();
		Span &operator=(const Span &src);
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		unsigned int getSize() const;
		std::vector<int> getVector() const;

		template <typename TIterator>
		void	fillVector(TIterator begin, TIterator end);
};

#endif