//
// Created by Vakhid Betrakhmadov on 31/03/2018.
//

#include "Client/MatConverter.h"

namespace server_client {

    MatConverter::MatConverter()
            : matrixSize(0),
              bufferSize(0),
              buffer() {
    }

    MatConverter::MatConverter(const Mat& mat)
            : matrixSize(mat.total() * mat.elemSize()),
              bufferSize(sizeof(int) * 3 + matrixSize),
              buffer(bufferSize) {
    }

    const vector<byte>& MatConverter::byteStream(const Mat &mat) {
        int type = mat.type();
        if (buffer.capacity() == 0) {
            matrixSize = mat.total() * mat.elemSize();
            bufferSize = sizeof(int) * 3 + matrixSize;
            buffer.reserve(bufferSize);
            auto backInserter = back_inserter(buffer);
            copy((byte*)&mat.rows, ((byte*)&mat.rows) + sizeof(int), backInserter);
            copy((byte*)&mat.cols, ((byte*)&mat.cols) + sizeof(int), backInserter);
            copy((byte*)&type, ((byte*)&type) + sizeof(int), backInserter);
            copy(mat.data, mat.data + matrixSize, backInserter);
        } else {
            copy((byte*)&mat.rows, ((byte*)&mat.rows) + sizeof(int), buffer.data());
            copy((byte*)&mat.cols, ((byte*)&mat.cols) + sizeof(int), buffer.data() + sizeof(int));
            copy((byte*)&type, ((byte*)&type) + sizeof(int), buffer.data() + sizeof(int) * 2);
            copy(mat.data, mat.data + matrixSize, buffer.data() + sizeof(int) * 3);
        }

        return buffer;
    }

    Mat MatConverter::makeMat(const vector<byte> &buffer) {
        int rows, cols, type;
        copy(buffer.data(), buffer.data() + sizeof(int), (byte*)&rows);
        copy(buffer.data() + sizeof(int), buffer.data() + sizeof(int) * 2, (byte*)&cols);
        copy(buffer.data() + sizeof(int) * 2, buffer.data() + sizeof(int) * 3, (byte*)&type);
        return Mat(rows, cols, type, (void*) (buffer.data() + sizeof(int) * 3));
    }
}
