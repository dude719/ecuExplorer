#if ! defined ( DRAWING_OBJECTS_GRID_CLASS_HEADER )

/*
** Author: Samuel R. Blackburn
** CI$: 76300,326
** Internet: sammy@sed.csc.com
**
** You can use it any way you like as long as you don't try to sell it.
**
** Any attempt to sell WFC in source code form must have the permission
** of the original author. You can produce commercial executables with
** WFC but you can't sell WFC.
**
** Copyright, 1995, Samuel R. Blackburn
*/

#define DRAWING_OBJECTS_GRID_CLASS_HEADER

class CDrawingObjectGrid : public CObject
{
   DECLARE_SERIAL( CDrawingObjectGrid )

   protected:

      void m_Initialize( void );
      void m_SetRectangles( void );

      DWORD m_NumberOfRows;
      DWORD m_NumberOfColumns;
      DWORD m_VerticalSpacing;
      DWORD m_HorizontalSpacing;

      CObArray m_ObjectArray;

      CString m_Name;

   public:

      CDrawingObjectGrid();
      CDrawingObjectGrid( DWORD number_of_rows, DWORD number_of_columns );

      virtual ~CDrawingObjectGrid();

      virtual void         Draw( CDC& device_context );
      virtual CRectangle*& ElementAt( DWORD row_number, DWORD column_number );
      virtual CRectangle*  GetAt( DWORD row_number, DWORD column_number );
      virtual DWORD        GetHeight( void ) const;
      virtual int          GetHorizontalSpacing( void ) const;
      virtual BOOL         GetIndexFromPoint( DWORD& row_index, DWORD& column_index, const CPoint& point );
      virtual void         GetName( CString& name_of_grid ) const;
      virtual DWORD        GetNumberOfColumns( void ) const;
      virtual DWORD        GetNumberOfRows( void ) const;
      virtual void         GetRectangle( CRect& rect ) const;
      virtual DWORD        GetVerticalSpacing( void ) const;
      virtual DWORD        GetWidth( void ) const;
      virtual void         RemoveAll( void );
      virtual void         Serialize( CArchive& archive );
      virtual void         SetAt( DWORD row_number, DWORD column_number, CRectangle *new_element );
      virtual void         SetFillColor( DWORD row_number, DWORD column_number, COLORREF color );
      virtual void         SetHorizontalSpacing( DWORD horizontal_spacing );
      virtual void         SetLineColor( DWORD row_number, DWORD columen_number, COLORREF color );
      virtual void         SetName( LPCTSTR name_of_grid = NULL );
      virtual void         SetRectangle( const CRect& source );
      virtual void         SetSize( DWORD number_of_rows, DWORD number_of_columns );
      virtual void         SetVerticalSpacing( DWORD vertical_spacing );

#if defined( _DEBUG )

      virtual void Dump( CDumpContext& dump_context ) const;

#endif // _DEBUG
};

#define LABELED_GRID_ROW_NAMES     1
#define LABELED_GRID_COLUMN_NAMES  2
#define LABELED_GRID_ROWS_TITLE    4
#define LABELED_GRID_COLUMNS_TITLE 8
#define LABELED_GRID_ALL_TITLES ( LABELED_GRID_ROW_NAMES | LABELED_GRID_COLUMN_NAMES | LABELED_GRID_ROWS_TITLE | LABELED_GRID_COLUMNS_TITLE )

class CLabeledGrid : public CDrawingObjectGrid
{
   DECLARE_SERIAL( CLabeledGrid )

   private:

      void m_Initialize( void );

   protected:

      CStringArray m_ColumnNames;
      CStringArray m_RowNames;

      CString m_RowsTitle;
      CString m_ColumnsTitle;

      DWORD m_ColumnFontSize;
      DWORD m_ColumnsTitleFontSize;
      DWORD m_RowFontSize;
      DWORD m_RowsTitleFontSize;
      DWORD m_NumberOfLogicalUnitsInLongestRowName;
      DWORD m_NumberOfLogicalUnitsInLongestColumnName;
      DWORD m_NumberOfLogicalUnitsInRowsTitle;
      DWORD m_NumberOfLogicalUnitsInColumnsTitle;
      DWORD m_LabelOptions;

      CFont m_RowNamesFont;
      CFont m_ColumnNamesFont;
      CFont m_RowsTitleFont;
      CFont m_ColumnsTitleFont;

      virtual void m_SetColumnFontSize( CDC& device_context, DWORD font_size );
      virtual void m_SetColumnsTitleFontSize( CDC& device_context, DWORD font_size );
      virtual void m_SetRowFontSize( CDC& device_context, DWORD font_size );
      virtual void m_SetRowsTitleFontSize( CDC& device_context, DWORD font_size );

   public:

      CLabeledGrid();
      CLabeledGrid( DWORD number_of_rows, DWORD number_of_columns );
      virtual ~CLabeledGrid();

      virtual void Draw( CDC& device_context );
      virtual void GetColumnName( DWORD column_number, CString& column_name ) const;
      virtual void GetColumnsTitle( CString& columns_title ) const;
      virtual void GetRowName( DWORD row_number, CString& row_name ) const;
      virtual void GetRowsTitle( CString& rows_title ) const;
      virtual void PrepareForPainting( CDC&  device_context,
                                       DWORD row_font_size           = 8,
                                       DWORD column_font_size        = 8,
                                       DWORD rows_title_font_size    = 14,
                                       DWORD columns_title_font_size = 14 );
      virtual void RemoveAll( void );
      virtual void Serialize( CArchive& archive );
      virtual void SetColumnName( DWORD column_number, LPCTSTR column_name );
      virtual void SetColumnsTitle( LPCTSTR columns_title = NULL );
      virtual void SetLabelOptions( DWORD options );
      virtual void SetRowName( DWORD row_number, LPCTSTR row_name );
      virtual void SetRowsTitle( LPCTSTR rows_title = NULL );
      virtual void SetSize( DWORD number_of_rows, DWORD number_of_columns );

#if defined( _DEBUG )

      virtual void Dump( CDumpContext& dump_context ) const;

#endif // _DEBUG
};

#endif // DRAWING_OBJECTS_GRID_CLASS_HEADER
