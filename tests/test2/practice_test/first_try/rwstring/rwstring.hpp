#ifndef RWSTRING_HPP_INCLUDED
#define RWSTRING_HPP_INCLUDED

void writestring(fstream &fs, string str, unsigned int size)
{
	str.resize(size);
	fs.write(str.data(), size);
}

string readstring(fstream &fs, unsigned int size)
{
	char *buffer = new char[size + 1];
	buffer[size] = '\0';
	fs.read(buffer, size);
	string str(buffer);
	delete[] buffer;
	return str;
}

#endif /* RWSTRING_HPP_INCLUDED */
