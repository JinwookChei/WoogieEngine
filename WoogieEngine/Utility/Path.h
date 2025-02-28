#pragma once


class Path {
public:
	UTILITY_API Path();

	UTILITY_API Path(const std::filesystem::path& path);

	UTILITY_API  ~Path();

	bool UTILITY_API IsRoot() const;

	bool UTILITY_API IsFile() const;

	bool UTILITY_API IsDirectory() const;

	bool UTILITY_API IsExists() const;

	std::string UTILITY_API GetPathString() const;

	std::wstring UTILITY_API GetPathWString() const;

	std::string UTILITY_API GetFileName() const;

	std::string UTILITY_API GetExtension() const;

	void UTILITY_API MoveParent();

	bool UTILITY_API Move(std::string_view _path);

	std::string UTILITY_API AppendPath(std::string_view path);

protected:
	std::filesystem::path currentPath_;
};