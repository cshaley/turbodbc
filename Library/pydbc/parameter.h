#pragma once

#include <cpp_odbc/statement.h>
#include <cpp_odbc/multi_value_buffer.h>
#include <pydbc/field.h>
#include <pydbc/description.h>

namespace pydbc {

/**
 * @brief This interface represents a single parameter of a query
 */
class parameter {
public:
	/**
	 * @brief Create a new parameter, binding an internal buffer to the statement
	 * @param statement The statement for which to bind a buffer
	 * @param one_based_index One-based parameter index for bind command
	 * @param buffered_rows Number of rows for which the buffer should be allocated
	 * @param desription Description concerning data type of parameter
	 */
	parameter(cpp_odbc::statement const & statement, std::size_t one_based_index, std::size_t buffered_rows, std::unique_ptr<description const> description);

	/**
	 * @brief Set the value of the parameter associated with the given row to the given value
	 * @param row_index Index of the row for which the value is set
	 * @param value Index of the row for which the value is set
	 */
	void set(std::size_t row_index, pydbc::field const & value);

	~parameter();
private:
	std::unique_ptr<description const> description_;
	cpp_odbc::multi_value_buffer buffer_;
};


}