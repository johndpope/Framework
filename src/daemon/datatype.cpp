#include "datatype.h"

using namespace datatypes;

std::map<EDataType, IAbstractDataTypeCreator*> CDataTypeFactory::m_types;

CDataTypeShares::CDataTypeShares(const std::list<std::string>& args) {
	m_success = (args.size() == EXPECTED_ARGS_NUM);
	if (m_success) {
		m_filename = args.front();
	}
}

EError CDataTypeShares::get_data(std::vector<char>& output) const {
	std::string full_path(CSettings::working_dir() + "data/" + m_data_dir + "/" + m_filename);
	std::ifstream file(full_path, std::ios::binary);
	if (!file) {
		return EError::OPEN_ERROR;
	}

	file.seekg(0, file.end);
	int size = file.tellg();
	file.seekg(0, file.beg);
	output.resize(size);

	if (!file.read(output.data(), size)) {
		file.close();
		return EError::READ_ERROR;
	}

	file.close();
	return EError::OK;
}

bool CDataTypeShares::success() const {
	return m_success;
}

EError CDataTypeShares::write_data(const std::vector<char>& input) const {
	std::string full_path(CSettings::working_dir() + "data/" + m_data_dir + "/" + m_filename);
	std::ofstream file(full_path, std::ios::binary);
	if (!file) {
		return EError::OPEN_ERROR;
	}

	if (!file.write(input.data(), input.size())) {
		file.close();
		return EError::WRITE_ERROR;
	}

	file.close();
	return EError::OK;
}
	

CDataTypeTwitter::CDataTypeTwitter(const std::list<std::string>& args) {
	m_success = (args.size() == EXPECTED_ARGS_NUM);
	if (m_success) {
		m_filename = args.front();
	}
}

EError CDataTypeTwitter::get_data(std::vector<char>& output) const {
	std::string full_path(CSettings::working_dir() + "data/" + m_data_dir + "/" + m_filename);
	std::ifstream file(full_path, std::ios::binary);
	if (!file) {
		return EError::OPEN_ERROR;
	}

	file.seekg(0, file.end);
	int size = file.tellg();
	file.seekg(0, file.beg);
	output.resize(size);

	if (!file.read(output.data(), size)) {
		file.close();
		return EError::READ_ERROR;
	}

	file.close();
	return EError::OK;
}

bool CDataTypeTwitter::success() const {
	return m_success;
}

EError CDataTypeTwitter::write_data(const std::vector<char>& input) const {
	std::string full_path(CSettings::working_dir() + "data/" + m_data_dir + "/" + m_filename);
	std::ofstream file(full_path, std::ios::binary);
	if (!file) {
		return EError::OPEN_ERROR;
	}

	if (!file.write(input.data(), input.size())) {
		file.close();
		return EError::WRITE_ERROR;
	}

	file.close();
	return EError::OK;
}

#ifdef TESTING
CDataTypeTest::CDataTypeTest(const std::list<std::string>& args) {
	m_success = (args.size() == EXPECTED_ARGS_NUM);
	if (m_success) {
		m_filename = args.front();
	}
}

bool CDataTypeTest::success() const {
	return m_success;
}

EError CDataTypeTest::get_data(std::vector<char>& output) const {
	std::string full_path(CSettings::working_dir() + "data/" + m_data_dir + "/" + m_filename);
	std::ifstream file(full_path, std::ios::binary);
	if (!file) {
		return EError::OPEN_ERROR;
	}

	file.seekg(0, file.end);
	int size = file.tellg();
	file.seekg(0, file.beg);
	output.resize(size);

	if (!file.read(output.data(), size)) {
		file.close();
		return EError::READ_ERROR;
	}

	file.close();
	return EError::OK;
}

EError CDataTypeTest::write_data(const std::vector<char>& input) const {
	std::string full_path(CSettings::working_dir() + "data/" + m_data_dir + "/" + m_filename);
	std::ofstream file(full_path, std::ios::binary);
	if (!file) {
		return EError::OPEN_ERROR;
	}

	if (!file.write(input.data(), input.size())) {
		file.close();
		return EError::WRITE_ERROR;
	}

	file.close();
	return EError::OK;
}
#endif //TESTING
