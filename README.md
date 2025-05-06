# PL/0 Lexer & Parser

## 📌 Giới thiệu
Bộ phân tích **từ vựng** (Lexer) và **cú pháp** (Parser) cho ngôn ngữ PL/0, được viết bằng ngôn ngữ lập trình C.  
Chương trình đọc mã nguồn từ tệp `.pl0`, phân tích token, kiểm tra cú pháp và thông báo lỗi (nếu có).

## 📁 Cấu trúc thư mục
```
📁 lexer_pl0
├── lexer.h         # Định nghĩa token và các hàm lexer
├── lexer.c         # Triển khai bộ phân tích từ vựng
├── parser.c        # Bộ phân tích cú pháp
├── main.c          # Chương trình chính khởi chạy lexer & parser
├── test.pl0        # Tệp mã nguồn PL/0 mẫu
├── Makefile        # (Tuỳ chọn) Dùng để biên dịch tự động
└── README.md       # Tài liệu hướng dẫn sử dụng
```

## ⚙️ Cài đặt và chạy

### 1. Biên dịch chương trình

#### ✅ Nếu có `Makefile`:
```bash
make
```

#### ✅ Nếu không có `Makefile`:
```bash
gcc -o parser lexer.c parser.c main.c
```

### 2. Chạy chương trình
Chạy chương trình với tệp mã nguồn PL/0:
```bash
./parser test.pl0
```

### 3. Kết quả đầu ra

- Nếu mã hợp lệ, chương trình in:
```
Phân tích cú pháp thành công.
```

- Nếu có lỗi cú pháp:
```
Lỗi cú pháp: Thiếu THEN (gặp 'x')
```

- Trong quá trình kiểm tra, tất cả token cũng có thể được in ra (nếu bạn bật debug trong `lexer.c`).

---

## 🧹 Dọn dẹp file biên dịch
Nếu dùng Makefile:
```bash
make clean
```

Nếu biên dịch thủ công:
```bash
rm parser
```

---

## 📎 Ghi chú

- Hỗ trợ các thành phần của ngôn ngữ PL/0: từ khóa (`VAR`, `IF`, `THEN`, ...), toán tử (`+`, `-`, `*`, `/`, `=`, `<>`, `<`, `<=`, `>`, `>=`), dấu câu (`;`, `.`, `:=`,...).
- Phân tích theo cấu trúc: **biểu thức**, **câu lệnh**, **điều kiện**, **chương trình**.
- Báo lỗi rõ ràng với thông báo tiếng Việt, giúp dễ học và debug.
