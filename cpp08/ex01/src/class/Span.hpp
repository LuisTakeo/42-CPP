#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <iterator>
# include <exception>

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
		int &operator[](unsigned int index);
		const int &operator[](unsigned int index) const;


		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		unsigned int getSize() const;
		std::vector<int> getVector() const;

		template <typename TIterator>
		void fillVector(TIterator begin, TIterator end)
		{
			if (this->_nums.size() + std::distance(begin, end) > this->_size)
				throw std::length_error("Span is full");

			this->_nums.insert(this->_nums.end(), begin, end);
		}

		void printValues() const;
};

struct PrintValue {
	template <typename T>
    void operator()(T &value) const {
        std::cout << value << " ";
    }

	template <typename T>
	void operator()(const T &value) const {
		std::cout << value << " ";
	}
};

std::ostream &operator<<(std::ostream &out, const Span &span);

#endif