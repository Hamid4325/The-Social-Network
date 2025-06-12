//#include<iostream>
//#include<fstream>
//using namespace std;
//
//class Obj;
//class Date;
//class Post;
//class User;
//class Page;
//class Memory;
//class Comment;
//
//class Helper {
//public:
//	// Gives the lenght of the given cstring
//	static int StringSize(const char string[]) {
//		int i = 0;
//		while (string[i] != '\0') {
//			i++;
//		}
//		return i;
//	}
//
//	// Copies one c-string to the other
//	static void Strcpy(char* str, const char str1[], int size) {
//
//		for (int i = 0; i < size; i++) {
//			str[i] = str1[i];
//		}
//		str[size] = '\0';
//	}
//
//	// Dynamically allocates memory and copy data in it.
//	static char* charBuffer(const char* str) {
//		int size = StringSize(str);
//		char* string = new char[size + 1];
//		Strcpy(string, str, size);
//		return string;
//	}
//
//	static bool StringCompare(char* str1, const char* str2) {
//		int size1 = StringSize(str1);
//		int size2 = StringSize(str2);
//
//		if (size1 == size2) {
//			for (int i = 0; i < size1; i++) {
//				if (str1[i] != str2[i]) {
//					return false;
//				}
//			}
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//};
//
//// Class to store Date of the posts
//class Date {
//private:
//	int date;
//	int month;
//	int year;
//
//public:
//	Date() {
//		date = 0;
//		month = 0;
//		year = 0;
//	}
//
//	Date(int date, int month, int year) {
//		this->date = date;
//		if (month <= 12 && month > 0) {
//			this->month = month;
//		}
//		else {
//			cout << "Invalid Date" << endl;
//			this->month = 0;
//		}
//
//		this->year = year;
//	}
//
//	int GetDate() {
//		return date;
//	}
//
//	int GetYear() {
//		return year;
//	}
//
//	int operator-(Date& rhs) {
//		if (year != rhs.year) {
//			return 10;
//		}
//		if (month == rhs.month) {
//			if ((date - rhs.date) <= 2) {
//				return abs(date - rhs.date);
//			}
//		}
//		else {
//			return 10;
//		}
//
//	}
//
//	void SetDate(int date, int month, int year) {
//		this->date = date;
//		if (month <= 12 && month > 0) {
//			this->month = month;
//		}
//		else {
//			cout << "Invalid Date" << endl;
//			this->month = 0;
//		}
//
//		this->year = year;
//	}
//
//	Date(int num) {
//		date = num;
//		month = num;
//		year = num;
//	}
//
//	Date& operator=(int num) {
//		this->date = num;
//		this->month = num;
//		this->year = num;
//		return *this;
//	}
//
//	void Print() {
//		if (17 == date && 4 == month && 2024 == year) {
//			cout << "21h";
//			return;
//		}
//		cout << date << "/" << month << "/" << year;
//	}
//
//	void PrintDate() {
//		cout << date << "/" << month << "/" << year;
//	}
//};
//
//
//// Base class to control User and Page derived classes and to store their timeline
//class Obj {
//protected:
//	Post** timeline;
//
//public:
//	Obj() {
//		timeline = nullptr;
//	}
//
//	virtual void AddPostToTimeline(Post* ptr) {
//	}
//
//	virtual void DisplayFriends() {
//	}
//
//	virtual void DisplayPages() {
//	}
//
//	virtual void ViewTimeline(Date current) {
//	}
//
//	virtual void PrintFrindsTimeline(Date current) {
//	}
//
//	virtual void PrintPagesTimeline(Date current) {
//	}
//
//	virtual void ViewHomeTimeline(Date current) {
//
//	}
//
//	virtual void ViewMemory(Date current) {
//	}
//
//	virtual void PrintName() {
//	}
//
//	virtual ~Obj() {
//		if (timeline) {
//			for (int i = 0; i < 10; i++) {
//				if (timeline[i] == nullptr) {
//					break;
//				}
//				delete timeline[i];
//				timeline[i] = nullptr;
//			}
//			delete[] timeline;
//			timeline = nullptr;
//		}
//	}
//};
//
//class Comment : public Obj {
//public:
//	char* CID;
//	Obj* CommentBy;
//	char* Text;
//
//public:
//
//	Comment() {
//		CID = nullptr;
//		CommentBy = nullptr;
//		Text = nullptr;
//	}
//
//	Comment(const char* id, Obj* ptr, const char* text) {
//		CID = Helper::charBuffer(id);
//		CommentBy = ptr;
//		Text = Helper::charBuffer(text);
//	}
//
//	void SetCID(const char* str) {
//		if (CID) {
//			delete[] CID;
//		}
//
//		CID = Helper::charBuffer(str);
//	}
//
//	void LoadDataFromFile(Obj* ptr, const char* text) {
//		CommentBy = ptr;
//		if (Text) {
//			delete[] Text;
//		}
//		Text = Helper::charBuffer((text + 1));
//	}
//
//	bool CheckID(const char* id) {
//		int size1 = Helper::StringSize(id);
//		int size2 = Helper::StringSize(CID);
//
//		if (size1 == size2) {
//			for (int i = 0; i < size1; i++) {
//				if (CID[i] != id[i]) {
//					return false;
//				}
//			}
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//	void PrintComment() {
//		cout << "\t\t\t";
//		CommentBy->PrintName();
//		cout << ":\"" << Text << "\"" << endl;
//	}
//
//	~Comment() {
//		delete[] CID;
//		delete[] Text;
//	}
//
//};
//
//// Post class to store the post of the user's and pages
//class Post {
//protected:
//	char* ID;
//	Obj* SharedBy;
//	Date SharedDate;
//	char* Text;
//	Obj** LikedBy;
//	Comment** Comments;
//
//public:
//	Post() {
//		ID = nullptr;
//		SharedBy = nullptr;
//		Text = nullptr;
//		LikedBy = nullptr;
//		Comments = nullptr;
//	}
//
//	void LoadDataFromFile(istream& fin) {
//		if (fin) {
//			char id[20], text[500];
//			fin >> id;
//			ID = Helper::charBuffer(id);
//
//			int date = 0, month = 0, year = 0;
//			fin >> date >> month >> year;
//			SharedDate.SetDate(date, month, year);
//
//			fin.ignore();
//			fin.getline(text, 500);
//			Text = Helper::charBuffer(text);
//		}
//	}
//
//	void SetSharedBy(Obj* ptr) {
//		SharedBy = ptr;
//	}
//
//	void SetLikedBy(Obj* ptr) {
//		if (LikedBy == nullptr) {
//			LikedBy = new Obj * [10];
//			for (int i = 0; i < 10; i++) {
//				LikedBy[i] = nullptr;
//			}
//		}
//
//		for (int i = 0; i < 10; i++) {
//			if (LikedBy[i] == nullptr) {
//				LikedBy[i] = ptr;
//				break;
//			}
//		}
//	}
//
//	void AddLikedBy(Obj* ptr) {
//		SetLikedBy(ptr);
//	}
//
//	bool CheckID(const char* id) {
//		int size1 = Helper::StringSize(id);
//		int size2 = Helper::StringSize(ID);
//
//		if (size1 == size2) {
//			for (int i = 0; i < size1; i++) {
//				if (ID[i] != id[i]) {
//					return false;
//				}
//			}
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//	void ViewLikedBy() {
//		for (int i = 0; i < 10; i++) {
//			if (LikedBy[i] == nullptr) {
//				break;
//			}
//			else {
//				LikedBy[i]->PrintName();
//				cout << endl;
//			}
//		}
//	}
//
//	void AddComment(Comment* comPtr) {
//		if (Comments == nullptr) {
//			Comments = new Comment * [10];
//
//			for (int i = 0; i < 10; i++) {
//				Comments[i] = nullptr;
//			}
//		}
//
//		for (int i = 0; i < 10; i++) {
//			if (Comments[i] == nullptr) {
//				Comments[i] = comPtr;
//				break;
//			}
//		}
//
//	}
//
//	Date GetDate() {
//		return SharedDate;
//	}
//
//	virtual void Print(Date current = 0, int comment = 0) {
//		cout << "";
//		SharedBy->PrintName();
//		cout << "(";
//		SharedDate.Print();
//		cout << ")" << endl;
//
//		cout << "\t\"" << Text << "\"" << endl;
//
//		if (Comments != nullptr) {
//			for (int i = 0; i < 10; i++) {
//				if (Comments[i] == nullptr) {
//					break;
//				}
//				if (comment == 0) {
//					Comments[i]->PrintComment();
//				}
//			}
//		}
//	}
//
//	virtual ~Post() {
//		if (ID != nullptr) {
//			delete[] ID;
//			ID = nullptr;
//		}
//		if (Text != nullptr) {
//			delete[] Text;
//			Text = nullptr;
//		}
//		if (LikedBy != nullptr) {
//			delete[] LikedBy;
//			LikedBy = nullptr;
//		}
//		if (Comments != nullptr) {
//			for (int i = 0; i < 10; i++) {
//				if (Comments[i] == nullptr) {
//					break;
//				}
//				delete Comments[i];
//				Comments[i] = nullptr;
//			}
//			delete[] Comments;
//			Comments = nullptr;
//		}
//	}
//};
//
//class Memory : public Post {
//private:
//	Post* OriginalPost;
//
//public:
//	Memory() {
//		OriginalPost = nullptr;
//	}
//
//	void ShareMemory(const char* id, Post* ptr, Obj* user, const char* text, Date& current) {
//		OriginalPost = ptr;
//		ID = Helper::charBuffer(id);
//		Text = Helper::charBuffer(text);
//		SharedDate = current;
//		SharedBy = user;
//		LikedBy = nullptr;
//		Comments = nullptr;
//	}
//
//	void Print(Date current = 0, int i = 0) {
//		cout << "~~~ ";
//		SharedBy->PrintName();
//		cout << " shared a memory ~~~ (1h)" << endl;
//
//		cout << "\t\"" << Text << "\"" << endl;
//
//		if (OriginalPost) {
//			cout << "\t~~~ " << abs(current.GetYear() - OriginalPost->GetDate().GetYear()) << " years ago ~~~" << endl;
//			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
//
//			OriginalPost->Print(1, 1);
//			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
//		}
//	}
//
//	~Memory() {
//		OriginalPost = nullptr;
//	}
//};
//
//
//// Page class stores the data for the pages
//class Page : public Obj {
//private:
//	char* ID;
//	char* Title;
//
//public:
//	Page() {
//		ID = nullptr;
//		Title = nullptr;
//	}
//
//	void LoadDataFromFile(istream& fin) {
//		if (fin) {
//			char id[20], title[80];
//			fin >> id;
//
//			fin.ignore();
//
//			fin.getline(title, 80);
//			ID = Helper::charBuffer(id);
//			Title = Helper::charBuffer(title);
//		}
//	}
//
//	void AddPostToTimeline(Post* ptr) {
//		if (timeline == nullptr) {
//			timeline = new Post * [10];
//			for (int i = 0; i < 10; i++) {
//				timeline[i] = nullptr;
//			}
//		}
//
//		for (int i = 0; i < 10; i++) {
//			if (timeline[i] == nullptr) {
//				timeline[i] = ptr;
//				break;
//			}
//		}
//	}
//
//	void ViewTimeline(Date current = 0) {
//		cout << Title << "- Timeline:" << endl;
//		if (timeline == nullptr) {
//			cout << "Add a Post first to view timeline." << endl;
//			return;
//		}
//		for (int i = 0; i < 10; i++) {
//			if (timeline[i] == nullptr) {
//				break;
//			}
//			timeline[i]->Print();
//			cout << endl;
//
//		}
//	}
//
//	void ViewHomeTimeline(Date current) {
//		if (timeline == nullptr) {
//			return;
//		}
//		for (int i = 0; i < 10; i++) {
//			if (timeline[i] == nullptr) {
//				break;
//			}
//			if ((timeline[i]->GetDate() - current) <= 1) {
//				timeline[i]->Print();
//				cout << endl;
//			}
//		}
//	}
//
//	void DisplayPage() {
//		cout << ID << " - " << Title << endl;
//	}
//
//	void PrintName() {
//		cout << Title;
//	}
//
//	bool CheckID(const char* id) {
//		int size1 = Helper::StringSize(id);
//		int size2 = Helper::StringSize(ID);
//
//		if (size1 == size2) {
//			for (int i = 0; i < size1; i++) {
//				if (ID[i] != id[i]) {
//					return false;
//				}
//			}
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//	~Page() {
//		delete[] ID;
//		delete[] Title;
//	}
//};
//
//// User class stores the data for users
//class User : public Obj {
//private:
//	char* ID;
//	char* fName;
//	char* lName;
//	User** Friends;	//null or 10 pointers MAX limit
//	Page** LikedPages; //null or 10 pointers MAX limit
//
//public:
//	User() {
//		ID = nullptr;
//		fName = nullptr;
//		lName = nullptr;
//		Friends = nullptr;
//		LikedPages = nullptr;
//	}
//
//	void LoadDataFromFile(istream& fin) {
//		if (fin) {
//			char id[20], fname[50], lname[50];
//			fin >> id >> fname >> lname;
//			ID = Helper::charBuffer(id);
//			fName = Helper::charBuffer(fname);
//			lName = Helper::charBuffer(lname);
//		}
//	}
//
//	void AddPostToTimeline(Post* ptr) {
//		if (timeline == nullptr) {
//			timeline = new Post * [10];
//			for (int i = 0; i < 10; i++) {
//				timeline[i] = nullptr;
//			}
//		}
//
//		for (int i = 0; i < 10; i++) {
//			if (timeline[i] == nullptr) {
//				timeline[i] = ptr;
//				break;
//			}
//		}
//	}
//
//	void ViewMemory(Date current) {
//		if (timeline == nullptr) {
//			return;
//		}
//		for (int i = 0; i < 10; i++) {
//			if (timeline[i] == nullptr) {
//				break;
//			}
//			if ((timeline[i]->GetDate().GetDate() == current.GetDate())) {
//				cout << "On this Day" << endl;
//				cout << abs(timeline[i]->GetDate().GetYear() - current.GetYear()) << " Years Ago" << endl;
//				timeline[i]->Print();
//				cout << endl;
//			}
//		}
//	}
//
//	void ViewTimeline(Date current = 0) {
//		cout << fName << " " << lName << " - Timeline:" << endl;
//		if (timeline == nullptr) {
//			cout << "No posts to display." << endl;
//			return;
//		}
//		for (int i = 0; i < 10; i++) {
//			if (timeline[i] == nullptr) {
//				break;
//			}
//			timeline[i]->Print(current);
//			cout << endl;
//		}
//	}
//
//	void ViewHomeTimeline(Date current) {
//		if (timeline == nullptr) {
//			return;
//		}
//		for (int i = 0; i < 10; i++) {
//			if (timeline[i] == nullptr) {
//				break;
//			}
//			if ((timeline[i]->GetDate() - current) <= 1) {
//				timeline[i]->Print();
//				cout << endl;
//			}
//		}
//	}
//
//	void PrintFrindsTimeline(Date current) {
//		if (timeline == nullptr) {
//			return;
//		}
//		int i = 0;
//		while (Friends[i] != nullptr) {
//			Friends[i]->ViewHomeTimeline(current);
//			i++;
//		}
//	}
//
//	void PrintPagesTimeline(Date current) {
//		if (timeline == nullptr) {
//			return;
//		}
//		int i = 0;
//		while (LikedPages[i] != nullptr) {
//			cout << endl;
//			LikedPages[i]->ViewHomeTimeline(current);
//			i++;
//		}
//	}
//
//	bool CheckID(const char* id) {
//		int size1 = Helper::StringSize(id);
//		int size2 = Helper::StringSize(ID);
//
//		if (size1 == size2) {
//			for (int i = 0; i < size1; i++) {
//				if (ID[i] != id[i]) {
//					return false;
//				}
//			}
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//	void AddFriend(User* frnd) {
//		if (Friends == nullptr) {
//			Friends = new User * [10];
//			Friends[0] = frnd;
//			for (int i = 1; i < 10; i++) {
//				Friends[i] = nullptr;
//			}
//		}
//		else {
//			for (int i = 0; i < 10; i++) {
//				if (Friends[i] == nullptr) {
//					Friends[i] = frnd;
//					break;
//				}
//			}
//		}
//	}
//
//	void DisplayFriends() {
//		cout << fName << " " << lName << " - Friend List:" << endl;
//		int i = 0;
//		while (Friends[i] != nullptr) {
//			cout << Friends[i]->ID << " - " << Friends[i]->fName << " " << Friends[i]->lName << endl;
//			i++;
//		}
//	}
//
//	void DisplayPages() {
//		cout << fName << " " << lName << " - Liked Pages:" << endl;
//		int i = 0;
//		if (LikedPages == nullptr) {
//			cout << "Liked Pages Not Found" << endl;
//			return;
//		}
//		while (LikedPages[i] != nullptr) {
//			LikedPages[i]->DisplayPage();
//			i++;
//		}
//	}
//
//	char* GetFname() {
//		return fName;
//	}
//
//	char* GetLname() {
//		return lName;
//	}
//
//	void PrintName() {
//		cout << fName << " " << lName;
//	}
//
//	void LikePage(Page* page) {
//		if (LikedPages == nullptr) {
//			LikedPages = new Page * [10];
//			LikedPages[0] = page;
//			for (int i = 1; i < 10; i++) {
//				LikedPages[i] = nullptr;
//			}
//		}
//		else {
//			for (int i = 0; i < 10; i++) {
//				if (LikedPages[i] == nullptr) {
//					LikedPages[i] = page;
//					break;
//				}
//			}
//		}
//	}
//
//	~User() {
//		delete[] ID;
//		delete[] fName;
//		delete[] lName;
//		if (Friends) {
//			delete[] Friends;
//		}
//		if (LikedPages) {
//			delete[] LikedPages;
//		}
//	}
//};
//
//
//
//// Controller class control the whole program from reading data to dislaying it.
//class Controller
//{
//private:
//	User** AllUser;
//	Page** AllPages;
//	Post** AllPosts;
//	Comment** AllComments;
//	int totalUsers;
//	int totalPages;
//	int totalPosts;
//	int totalComments;
//
//public:
//	Controller() {
//		AllUser = nullptr;
//		AllPages = nullptr;
//		AllPosts = nullptr;
//		AllComments = nullptr;
//		totalUsers = 0;
//		totalPages = 0;
//		totalPosts = 0;
//		totalComments = 0;
//	}
//
//	User* SearchUserByID(const char* ID) {
//		for (int i = 0; i < totalUsers; i++) {
//			if (AllUser[i]->CheckID(ID)) {
//				return AllUser[i];
//			}
//		}
//		return nullptr;
//	}
//
//	Page* SearchPageByID(const char* ID) {
//		for (int i = 0; i < totalPages; i++) {
//			if (AllPages[i]->CheckID(ID)) {
//				return AllPages[i];
//			}
//		}
//		return nullptr;
//	}
//
//	Post* SearchPostByID(const char* ID) {
//		for (int i = 0; i < totalPosts; i++) {
//			if (AllPosts[i]->CheckID(ID)) {
//				return AllPosts[i];
//			}
//		}
//		return nullptr;
//	}
//
//	Obj* SearchObjByID(const char* ID) {
//		if (ID[0] == 'u') {
//			return (SearchUserByID(ID));
//		}
//		else {
//			return (SearchPageByID(ID));
//		}
//	}
//
//	Comment* SearchCommentByID(const char* ID) {
//		for (int i = 0; i < totalComments; i++) {
//			if (AllComments[i]->CheckID(ID)) {
//				return AllComments[i];
//			}
//		}
//		return nullptr;
//	}
//
//	void LoadUsersFromFile(const char* filename) {
//		ifstream fin(filename);
//		if (!fin) {
//			cout << "Error: Unable to open file " << filename << endl;
//			return;
//		}
//		if (fin.is_open()) {
//			fin >> totalUsers;
//
//			AllUser = new User * [totalUsers];
//			for (int i = 0; i < totalUsers; i++) {
//				AllUser[i] = new User();
//				AllUser[i]->LoadDataFromFile(fin);
//			}
//
//			fin.close();
//		}
//
//	}
//
//	void LoadPagesFromFile(const char* filename) {
//		ifstream fin(filename);
//		if (!fin) {
//			cout << "Error: Unable to open file " << filename << endl;
//			return;
//		}
//		totalPages;
//		fin >> totalPages;
//
//		AllPages = new Page * [totalPages];
//		for (int i = 0; i < totalPages; i++) {
//			AllPages[i] = new Page();
//			AllPages[i]->LoadDataFromFile(fin);
//		}
//
//		fin.close();
//	}
//
//	void LoadPostsFromFile(const char* filename) {
//		ifstream fin(filename);
//		if (!fin) {
//			cout << "Error: Unable to open file " << filename << endl;
//			return;
//		}
//		fin >> totalPosts;
//
//		AllPosts = new Post * [totalPosts];
//		for (int i = 0; i < totalPosts; i++) {
//			AllPosts[i] = new Post();
//			AllPosts[i]->LoadDataFromFile(fin);
//
//			char id[20];
//			fin >> id;
//			AllPosts[i]->SetSharedBy(SearchObjByID(id));
//			AddPostToTimeline(SearchObjByID(id), AllPosts[i]);
//
//			fin >> id;
//			while (!Helper::StringCompare(id, "-1")) {
//				AllPosts[i]->SetLikedBy(SearchObjByID(id));
//				fin >> id;
//			}
//		}
//		fin.close();
//	}
//
//	void LoadCommentsFromFile(const char* filename) {
//		ifstream fin(filename);
//		if (!fin) {
//			cout << "Error: Unable to open file " << filename << endl;
//			return;
//		}
//		fin >> totalComments;
//
//		AllComments = new Comment * [totalComments];
//		for (int i = 0; i < totalComments; i++) {
//			char ID[20], postId[20], userId[20], text[500];
//			AllComments[i] = new Comment();
//			fin >> ID;
//			AllComments[i]->SetCID(ID);
//			fin >> postId;
//			Post* postPtr = SearchPostByID(postId);
//			postPtr->AddComment(AllComments[i]);
//			fin >> userId;
//			Obj* Id = SearchObjByID(userId);
//			fin.getline(text, 500);
//			AllComments[i]->LoadDataFromFile(Id, text);
//		}
//		fin.close();
//	}
//
//	void AddPostToTimeline(Obj* ptr, Post* post) {
//		ptr->AddPostToTimeline(post);
//	}
//
//	void LinkUsersAndPages(const char* filename) {
//		ifstream fin(filename);
//		if (!fin) {
//			cout << "Error: Unable to open file " << filename << endl;
//			return;
//		}
//		char user[20], userF[20], page[20];
//		fin >> user;
//		while (!Helper::StringCompare(user, "-1")) {
//			User* temp = SearchUserByID(user);
//			fin >> userF;
//			while (!Helper::StringCompare(userF, "-1")) {
//				temp->AddFriend(SearchUserByID(userF));
//				fin >> userF;
//			}
//
//			fin >> page;
//			while (!Helper::StringCompare(page, "-1")) {
//				temp->LikePage(SearchPageByID(page));
//				fin >> page;
//			}
//			fin >> user;
//		}
//		fin.close();
//	}
//
//	Obj* SetCurrent(const char* cur) {
//		Obj* current = SearchObjByID(cur);
//
//		if (current != nullptr) {
//			current->PrintName();
//
//			cout << " successfully set as Current." << endl;
//		}
//		return current;
//	}
//
//	void DisplayFriends(Obj* user) {
//		if (user != nullptr) {
//			user->DisplayFriends();
//		}
//		else {
//			cout << "Current User not set." << endl;
//		}
//	}
//
//	void DisplayLikedPages(Obj* user) {
//		if (user != nullptr) {
//			user->DisplayPages();
//		}
//		else {
//			cout << "Current User not set." << endl;
//		}
//	}
//
//	void Command(Obj*& user) {
//		cout << "------------------------------------------------------------------------------" << endl;
//		/*char command[100];*/
//		cout << "Enter ID" << endl;
//		cout << "Command:\tu7" << endl;
//		/*cin.getline(command, 100);*/
//
//		user = SetCurrent("u7");
//		cout << "------------------------------------------------------------------------------" << endl;
//		cout << endl << endl;
//	}
//
//	void ViewFrnd(Obj*& user) {
//		cout << "------------------------------------------------------------------------------" << endl;
//		cout << "Command:\tView Friend List" << endl;
//		cout << "------------------------------------------------------------------------------" << endl;
//		DisplayFriends(user);
//		cout << "------------------------------------------------------------------------------" << endl;
//		cout << endl << endl;
//	}
//
//	void ViewPages(Obj*& user) {
//		cout << "------------------------------------------------------------------------------" << endl;
//		cout << "Command:\tView Liked Pages" << endl;
//		cout << "------------------------------------------------------------------------------" << endl;
//		DisplayLikedPages(user);
//		cout << "------------------------------------------------------------------------------" << endl;
//		cout << endl << endl;
//	}
//
//	void Timeline(Obj* user, Date current) {
//		cout << "------------------------------------------------------------------------------" << endl;
//		cout << "Command:\tView Timeline of ";
//		user->PrintName();
//		cout << endl;
//		cout << "------------------------------------------------------------------------------" << endl;
//		user->ViewTimeline(current);
//		cout << "------------------------------------------------------------------------------" << endl;
//		cout << endl << endl;
//	}
//
//	void ViewLikedList() {
//		cout << "------------------------------------------------------------------------------" << endl;
//		cout << "Command:\tView Liked List (post5)" << endl;
//		cout << "------------------------------------------------------------------------------" << endl;
//		Post* post = SearchPostByID("post5");
//		post->ViewLikedBy();
//		cout << "------------------------------------------------------------------------------" << endl;
//		cout << endl << endl;
//	}
//
//	void LikePost(Obj* user) {
//		cout << "------------------------------------------------------------------------------" << endl;
//		cout << "Command:\tLike Post (post5) by ";
//		user->PrintName();
//		cout << endl;
//		cout << "------------------------------------------------------------------------------" << endl;
//		Post* post = SearchPostByID("post5");
//		post->AddLikedBy(user);
//		cout << endl << endl;
//	}
//
//	void ShowCurrentDate(Date current) {
//		cout << "------------------------------------------------------------------------------" << endl;
//		cout << "Current Date \t";
//		current.PrintDate();
//		cout << endl;
//		cout << "------------------------------------------------------------------------------" << endl;
//		cout << endl << endl;
//	}
//
//	void ViewHome(Obj* user, Date current) {
//		cout << "------------------------------------------------------------------------------" << endl;
//		cout << "Command:\tView Home" << endl;
//		user->PrintName();
//		cout << " - Home Page";
//		cout << endl;
//		cout << "------------------------------------------------------------------------------" << endl;
//		user->ViewHomeTimeline(current);
//		user->PrintFrindsTimeline(current);
//		user->PrintPagesTimeline(current);
//
//		cout << "------------------------------------------------------------------------------" << endl;
//		cout << endl << endl;
//	}
//
//	void AddComment(Obj* currentPage, const char* id, const char* cid, const char* text) {
//		cout << "------------------------------------------------------------------------------" << endl;
//		cout << "Command:\tPostComment(" << id << ", \"" << text << "\")" << endl;
//		cout << "------------------------------------------------------------------------------" << endl;
//
//		Post* targetPost = SearchPostByID(id);
//		if (!targetPost) {
//			cout << "Error: Post '" << id << "' not found. Cannot add comment." << endl;
//			cout << "------------------------------------------------------------------------------" << endl << endl;
//			return;
//		}
//		if (!currentPage) {
//			cout << "Error: Cannot add comment without a valid commenter (user/page)." << endl;
//			cout << "------------------------------------------------------------------------------" << endl << endl;
//			return;
//		}
//
//		int newCommentIndex = totalComments; 
//		totalComments++; 
//
//		Comment* newHeapComment = new Comment(cid, currentPage, text);
//
//		Comment** tempComments = new Comment * [totalComments];
//		for (int i = 0; i < totalComments - 1; ++i) { 
//			tempComments[i] = AllComments[i];
//		}
//		tempComments[totalComments - 1] = newHeapComment;
//		delete[] AllComments;      
//		AllComments = tempComments;
//
//		targetPost->AddComment(newHeapComment);
//
//		cout << endl << endl;
//	}
//
//	void ViewPost(const char* id) {
//		cout << "------------------------------------------------------------------------------" << endl;
//		cout << "Command:\tViewPost(" << id << ")" << endl;
//		cout << "------------------------------------------------------------------------------" << endl;
//		Post* post = SearchPostByID(id);
//		post->Print();
//		cout << "------------------------------------------------------------------------------" << endl;
//		cout << endl << endl;
//	}
//
//	void SeeYourMemories(Obj* user, Date current) {
//		cout << "------------------------------------------------------------------------------" << endl;
//		cout << "Command:\tSeeYourMemories()" << endl;
//		cout << "------------------------------------------------------------------------------" << endl;
//		cout << "We hope you enjoy looking back and sharing your memories\n on Facebook, from the most recent to those long ago." << endl << endl;
//		user->ViewMemory(current);
//		cout << "------------------------------------------------------------------------------" << endl;
//		cout << endl << endl;
//	}
//
//	void ShareMemory(const char* id, const char* postId, Obj* user, const char* text, Date current) {
//		cout << "------------------------------------------------------------------------------" << endl;
//		cout << "Command:\tShareMemory(" << postId << ", " << text << ")" << endl;
//		cout << "------------------------------------------------------------------------------" << endl;
//
//		Post* originalPost = SearchPostByID(postId);
//		if (!originalPost) {
//			cout << "Error: Post not found." << endl;
//			return;
//		}
//
//		Memory* memory = new Memory();
//		memory->ShareMemory(id, originalPost, user, text, current);
//
//		user->AddPostToTimeline(memory);
//
//		totalPosts++;
//		Post** temp = new Post * [totalPosts];
//		for (int i = 0; i < totalPosts - 1; ++i) {
//			temp[i] = AllPosts[i];
//		}
//		temp[totalPosts - 1] = memory;
//		delete[] AllPosts;
//		AllPosts = temp;
//
//		cout << "Memory shared successfully!" << endl;
//		cout << "------------------------------------------------------------------------------" << endl;
//		cout << endl << endl;
//	}
//
//	void LoadData(Date current) {
//		Obj* currentUser = nullptr;
//		ShowCurrentDate(current);
//		LoadUsersFromFile("Users.txt");
//		LoadPagesFromFile("Pages.txt"); //Do yourself
//		LinkUsersAndPages("FriendsAndLiked.txt");
//		LoadPostsFromFile("Posts.txt");
//		LoadCommentsFromFile("Comments.txt");
//		Command(currentUser);
//		ViewFrnd(currentUser);
//		ViewPages(currentUser);
//
//		Obj* currentPage = SearchObjByID("u7");
//		Timeline(currentPage, current);
//		ViewLikedList();
//		LikePost(currentPage);
//		ViewLikedList();
//		currentPage = SearchObjByID("p9");
//		Timeline(currentPage, current);
//
//		currentPage = SearchObjByID("u7");
//		ViewHome(currentPage, current);
//
//		AddComment(currentPage, "post4", "c14", "Good Luck for your Result again for testing.");
//		ViewPost("post4");
//
//		AddComment(currentPage, "post8", "c15", "Thanks for the wishes");
//		ViewPost("post8");
//
//		SeeYourMemories(currentPage, current);
//
//		ShareMemory("post21", "post10", currentPage, "Never thought I will be specialist in this field…", current);
//		Timeline(currentPage, current);
//
//		SeeYourMemories(currentPage, current);
//	}
//
//	~Controller() {
//		if (AllUser) {
//			for (int i = 0; i < totalUsers; i++) {
//				if (AllUser[i])
//					delete AllUser[i];
//			}
//			delete[] AllUser;
//		}
//
//		if (AllPages) {
//			for (int i = 0; i < totalPages; i++) {
//				if (AllPages[i])
//					delete AllPages[i];
//			}
//			delete[] AllPages;
//		}
//
//		if (AllPosts) {
//			delete[] AllPosts;
//		}
//		
//		if (AllComments) {
//			delete[] AllComments;
//		}
//	}
//};
//
//int main()
//{
//	//Current date for comparisons
//	Date current(17, 4, 2024);
//	Controller myApp;
//	myApp.LoadData(current);
//}