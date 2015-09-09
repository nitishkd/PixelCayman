/**
 * \file
 *
 * \author Mattia Basaglia
 *
 * \copyright Copyright (C) 2015 Mattia Basaglia
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef PIXEL_CAYMAN_TOOL_PAINT_HPP
#define PIXEL_CAYMAN_TOOL_PAINT_HPP

#include "tool.hpp"

#include <QIcon>
#include <QPainter>

namespace tool {

class Paint : public Tool
{
public:
    Paint();
    ~Paint();

    QIcon icon() const override;
    QString name() const override;
    QString description() const override;
    bool initialize(view::GraphicsWidget* widget) override;
    void finalize(view::GraphicsWidget* widget) override;
    void mousePressEvent(const QMouseEvent* event, view::GraphicsWidget* widget) override;
    void mouseMoveEvent(const QMouseEvent* event, view::GraphicsWidget* widget) override;
    void mouseReleaseEvent(const QMouseEvent* event, view::GraphicsWidget* widget) override;
    void drawForeground(QPainter* painter, view::GraphicsWidget* widget) override;
    QWidget* optionsWidget() override;
    QCursor cursor(const view::GraphicsWidget* widget) const override;

protected:
    void render(document::Image& image);

    void draw(view::GraphicsWidget* widget);

private:
    /**
     * \brief Set the brush to use a p-norm ball with the given diameter
     */
    void ballBrush(int diameter, qreal p_norm);

    void rectangleBrush(const QSize& size);

    void drawForegroundImpl(QPainter* painter);

    QLine  line;
    bool   draw_line = false;

    QImage       brush_mask;
    QPainterPath brush_path;

    class Widget;
    Widget* options_widget;
};

} // namespace tool
#endif // PIXEL_CAYMAN_TOOL_PAINT_HPP
