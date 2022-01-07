#pragma once
#include<ostream>
//#include"wx/listctrl.h"
#include"wx/wx.h"


static size_t DvDid = 0;

class DvD //: public wxListItem
{

	friend std::ostream &operator<<(const std::ostream& oStream, const DvD& dvd);

private:
	//the title of the movie
	wxString m_dvdTitle;
	//first star in the movie
	wxString m_movieStar1;
	//second star in the movie
	wxString m_movieStar2;
	//the producer of the movie
	wxString m_movieProducer;
	//the producer cooperator of the movie
	wxString m_productionCompagnie;
	//the director of the movie
	wxString m_movieDirector;
	// nomber of this dvd in stock
	size_t m_numberInStock;
	//dvd info

public:
	void setDVDInfo(wxString& title,
		wxString& star1,
		wxString& star2,
		wxString& producer,
		wxString& director,
		wxString& productionCo,
		int setInStock);

	constexpr size_t getNumOfCopiesInStock()const { return m_numberInStock; }
	void setNumOfCopiesInStock(size_t num) { m_numberInStock = num; }
	void checkOut();
	void chechIn();
	void updateNumOfCopiesInStock(size_t num);
	wxString getTitle()const { return m_dvdTitle; }
	wxString getStar1()const { return m_movieStar1; }
	wxString getStar2()const { return m_movieStar2; }
	wxString getProducer()const { return m_movieProducer; }
	wxString getProductionCompagnie()const { return m_productionCompagnie; }
	wxString getDirector()const { return m_movieDirector; }

	void setTitle(wxString& title) {  m_dvdTitle = title; }
	void setStar1(wxString& star1) {  m_movieStar1 = star1; }
	void setStar2(wxString&star2) {  m_movieStar2 = star2; }
	void setProducer(wxString& producer) {  m_movieProducer = producer; }
	void setProductionCompagnie(wxString& productionCo) {  m_productionCompagnie = productionCo; }
	void setDirector(wxString& director) {  m_movieDirector = director; }
	
	void setTitle(wxString&& title) {  m_dvdTitle = title; }
	void setStar1(wxString&& star1) {  m_movieStar1 = star1; }
	void setStar2(wxString&&star2) {  m_movieStar2 = star2; }
	void setProducer(wxString&& producer) {  m_movieProducer = producer; }
	void setProductionCompagnie(wxString&& productionCo) {  m_productionCompagnie = productionCo; }
	void setDirector(wxString&& director) {  m_movieDirector = director; }

	bool checkTitle(wxString& title) { return m_dvdTitle == title; }
	bool checkTitle(wxString&& title) { return m_dvdTitle == title; }

	DvD(wxString title = "",
		wxString star1 = "",
		wxString star2 = "",
		wxString producer = "",
		wxString director = "",
		wxString productionCom = "",
		size_t setInStock = 0);

	bool operator==(const DvD& otherDVD)const;
	bool operator!=(const DvD& otherDVD)const;
	bool operator<=(const DvD& otherDVD)const;
	bool operator>=(const DvD& otherDVD)const;
	bool operator<(const DvD& otherDVD)const;
	bool operator>(const DvD& otherDVD)const;

};

